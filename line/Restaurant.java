public class Restaurant {
    private int numberOfSeats;
    private int numberOfAvailableSeats;
    private int stayTime;
    private String openingHours;
    private int numberOfTimeSlots;
    private String[] timeSlots;

    public String getNumberOfAvailableSeats() {
        return numberOfAvailableSeats;
    }

    public void setNumberOfAvailableSeats() {
        this.numberOfAvailableSeats = numberOfSeats;
    }

    public void setInfo(String info) {
        String[] tokens = s.split(" ");

        // numberOfSeats
        int numberOfSeats = Integer.parseInt(tokens[0]);
        this.numberOfSeats = numberOfSeats;

        // stayTime
        int stayTime = Integer.parseInt(tokens[1]);
        this.stayTime = stayTime;

        // openingHours
        this.openingHours = tokens[2];

        // numberOfTimeSlots;
        int numberOfTimeSlots = Integer.parseInt(tokens[3]);
        this.numberOfTimeSlots = numberOfTimeSlots;

        // timeslots
    }
}