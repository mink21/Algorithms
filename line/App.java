package track;
import java.util.Scanner;
import java.util.ArrayList;

public class App {
  
  public static void main(String[] args) {
    String[] lines = getStdin();

    //restaurant info
    String line = lines[0];
    Restaurant restaurant = new Restaurant();
    restaurant.setInfo(line);

    //queries
    for (int i = 1, l = lines.length; i < l; i++) {
      //String output = String.format("line[%s]: %s", i, lines[i]);
      //System.out.println(output);
      line = lines[i];
      String[] tokens = s.split(" ");    
      int date = Integer.parseInt(tokens[0]);
      String queryTime = tokens[1];

      if(tokens[2] == 'time'){
        timeQuery(tokens[3]);
      }else if(tokens[3]== 'issue-unspecified'){
        issueQuery(tokens[3]);
      }else if(line[8] == 'available'){
        availableQuery();
      }else{
        System.out.println("input error");
      }
    }
  }

  private void timeQuery(String x){
    int timeSlot = Integer.parseInt(x);
    if(timeSlot == 1){
      //ticket disable
      Restaurant restaurant = new Restaurant();
      restaurant.setNumberOfAvailableSeats();
    }
  }

  private void issueQuery(String ticketNumber){
    int ticketNumber = Integer.parseInt(ticketNumber);
    //check 
  }

  private void availableQuery(){
    //ehck ticket
    ;
  }

  private static String[] getStdin() {
    Scanner scanner = new Scanner(System.in);
    ArrayList<String> lines = new ArrayList<>();
    while (scanner.hasNext()) {
      lines.add(scanner.nextLine());
    }
    return lines.toArray(new String[lines.size()]);
  }
}
