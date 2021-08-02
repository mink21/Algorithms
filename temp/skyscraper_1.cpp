#include "skyscrapers.h"

#include <algorithm>
#include <cassert>
#include <numeric>
#include <unordered_set>

#include <chrono>
#include <iostream>

class Nopes
{
public:
    Nopes(int size);

    void insert(int value);

    bool sizeReached() const;
    int missingNumberInSequence() const;

    bool contains(int value) const;

    bool isEmpty() const;

    // for debug print
    std::unordered_set<int> values() const;

private:
    int mSize;
    std::unordered_set<int> mValues;
};

Nopes::Nopes(int size) : mSize{size}
{
    assert(size > 0);
}

void Nopes::insert(int value)
{
    assert(value >= 1 && value <= mSize + 1);
    mValues.insert(value);
}

bool Nopes::sizeReached() const
{
    return mValues.size() == static_cast<std::size_t>(mSize);
}

int Nopes::missingNumberInSequence() const
{
    assert(sizeReached());
    int n = mValues.size() + 1;
    int projectedSum = (n + 1) * (n / 2);
    int actualSum = std::accumulate(mValues.begin(), mValues.end(), 0);
    return projectedSum - actualSum;
}

bool Nopes::contains(int value) const
{
    auto it = mValues.find(value);
    return it != mValues.end();
}

bool Nopes::isEmpty() const
{
    return mValues.empty();
}

std::unordered_set<int> Nopes::values() const
{
    return mValues;
}

struct Point
{
    int x;
    int y;
};

enum class BorderPosition
{
    top,
    right,
    bottom,
    left
};

void nextDirection(BorderPosition &borderPosition)
{
    if (borderPosition == BorderPosition::left)
    {
        borderPosition = BorderPosition::top;
    }
    else
    {
        int dir = static_cast<int>(borderPosition);
        ++dir;
        borderPosition = static_cast<BorderPosition>(dir);
    }
}

void advanceToNextPosition(Point &point, BorderPosition borderPosition,
                           int clueIdx)
{
    if (clueIdx == 0)
    {
        return;
    }
    switch (borderPosition)
    {
    case BorderPosition::top:
        ++point.x;
        break;
    case BorderPosition::right:
        ++point.y;
        break;
    case BorderPosition::bottom:
        --point.x;
        break;
    case BorderPosition::left:
        --point.y;
        break;
    }
}

class BorderIterator
{
public:
    BorderIterator(std::size_t boardSize);

    Point point() const;
    BorderPosition borderPosition() const;

    BorderIterator &operator++();

private:
    int mIdx = 0;
    std::size_t mBoardSize;
    Point mPoint{0, 0};
    BorderPosition mReadDirection{BorderPosition::top};
};

BorderIterator::BorderIterator(std::size_t boardSize) : mBoardSize{boardSize}
{
}

Point BorderIterator::point() const
{
    return mPoint;
}

BorderPosition BorderIterator::borderPosition() const
{
    return mReadDirection;
}

BorderIterator &BorderIterator::operator++()
{
    ++mIdx;
    if (mIdx != 0 && mIdx % mBoardSize == 0)
    {
        nextDirection(mReadDirection);
    }

    advanceToNextPosition(mPoint, mReadDirection, mIdx % mBoardSize);
    return *this;
}

struct Board
{
    Board(int size);

    std::array<std::array<int, 4>, 4> skyscrapers{};
    std::array<std::array<Nopes, 4>, 4> nopes;
};

Board::Board(int size)
    : nopes{{
          {Nopes{size - 1}, Nopes{size - 1}, Nopes{size - 1}, Nopes{size - 1}},
          {Nopes{size - 1}, Nopes{size - 1}, Nopes{size - 1}, Nopes{size - 1}},
          {Nopes{size - 1}, Nopes{size - 1}, Nopes{size - 1}, Nopes{size - 1}},
          {Nopes{size - 1}, Nopes{size - 1}, Nopes{size - 1}, Nopes{size - 1}},
      }}
{
}

class Slice
{
public:
    Slice(Board &board, const Point &startPoint, BorderPosition borderPosition,
          int clue);

    void insertSkyscraper(int skyscraper, std::size_t idx);
    void insertNope(int nope, std::size_t idx);

    int skyscraper(std::size_t idx) const;
    Nopes nopes(std::size_t idx) const;

    std::size_t size() const;

    int clue() const;

    bool isFull() const;

private:
    void addSkyscraperAndNopesFromClue();

    void addNopesAndSkyscrapersIfOneSkyscraperVisible();
    void addNopesIfTwoSkyscrapersVisible();
    void addNopesIfThreeSkyscrapersVisible();
    void addSkyscrapersIfAllSkyscrapersVisible();

    Point calcPosition(int idx) const;

    Board &mBoard;
    Point mStartPoint;
    BorderPosition mDirection;
    int mClue;
    std::size_t mBoardSize;
    mutable bool mIsfull{false};
};

Slice::Slice(Board &board, const Point &startPoint,
             BorderPosition borderPosition, int clue)
    : mBoard{board}, mStartPoint{startPoint}, mDirection{borderPosition},
      mClue{clue}, mBoardSize{mBoard.skyscrapers.size()}
{
    assert(mClue >= 0 && mClue <= static_cast<int>(mBoardSize));
    if (mClue != 0)
    {
        addSkyscraperAndNopesFromClue();
    }
    /*
    Clue 1 and 4 cannot give us any more information so its not best to mark
    them as not existing for the follow up algorithm iterating over the slices
    */
    if (mClue != 2 && mClue != 3)
    {
        mClue = 0;
    }
}

void Slice::insertSkyscraper(int skyscraper, std::size_t idx)
{
    Point p = calcPosition(idx);
    mBoard.skyscrapers[p.y][p.x] = skyscraper;
}

void Slice::insertNope(int nope, std::size_t idx)
{
    Point p = calcPosition(idx);
    mBoard.nopes[p.y][p.x].insert(nope);

    if (mBoard.nopes[p.y][p.x].sizeReached())
    {
        int missingSkyscraper =
            mBoard.nopes[p.y][p.x].missingNumberInSequence();
        insertSkyscraper(missingSkyscraper, idx);
    }
}

int Slice::skyscraper(std::size_t idx) const
{
    Point p = calcPosition(idx);
    return mBoard.skyscrapers[p.y][p.x];
}

Nopes Slice::nopes(std::size_t idx) const
{
    Point p = calcPosition(idx);
    return mBoard.nopes[p.y][p.x];
}

std::size_t Slice::size() const
{
    return mBoardSize;
}

int Slice::clue() const
{
    return mClue;
}

bool Slice::isFull() const
{
    if (mIsfull)
    {
        return mIsfull;
    }
    for (std::size_t i = 0; i < size(); ++i)
    {
        if (skyscraper(i) == 0)
        {
            return false;
        }
    }
    mIsfull = true;
    return mIsfull;
}

void Slice::addSkyscraperAndNopesFromClue()
{
    switch (mClue)
    {
    case 1:
        addNopesAndSkyscrapersIfOneSkyscraperVisible();
        break;
    case 2:
        addNopesIfTwoSkyscrapersVisible();
        break;
    case 3:
        addNopesIfThreeSkyscrapersVisible();
        break;
    case 4:
        addSkyscrapersIfAllSkyscrapersVisible();
        break;
    default:
        assert(false);
    }
}

void Slice::addNopesAndSkyscrapersIfOneSkyscraperVisible()
{
    insertSkyscraper(mBoardSize, 0);
    for (std::size_t i = 1; i < size(); ++i)
    {
        if (skyscraper(i) == 0)
        {
            continue;
        }
        insertNope(mBoardSize, i);
    }
}

void Slice::addNopesIfTwoSkyscrapersVisible()
{
    if (skyscraper(0) == 0)
    {
        insertNope(mBoardSize, 0);
    }
    if (skyscraper(1) == 0)
    {
        insertNope(mBoardSize - 1, 1);
    }
}

void Slice::addNopesIfThreeSkyscrapersVisible()
{
    if (skyscraper(0) == 0)
    {
        insertNope(mBoardSize - 1, 0);
