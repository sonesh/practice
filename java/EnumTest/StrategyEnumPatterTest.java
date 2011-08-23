/** Note: In general, don't use doubles for monetary calculations
 *  Ok for this toy example
 */
import java.util.HashMap;
import java.util.Map;


enum PayrollDay {

  MONDAY    (PayType.WEEKDAY),
  TUESDAY   (PayType.WEEKDAY),
  WEDNESDAY (PayType.WEEKDAY),
  THURSDAY  (PayType.WEEKDAY),
  FRIDAY    (PayType.WEEKDAY),
  SATURDAY  (PayType.WEEKEND),
  SUNDAY    (PayType.WEEKEND);

  private final PayType payType;
  
  double pay (int hoursWorked, double payRate) {
    return payType.pay(hoursWorked, payRate);
  }

  //Constructors
  PayrollDay (PayType payType) {
    this.payType = payType;
  }

  private static final Map<Integer, PayrollDay> dayOfWeekToPayrollDay
    = new HashMap<Integer, PayrollDay>();

  private static final int FIRST_DAY_OF_WEEK = 1;
  private static final int LAST_DAY_OF_WEEK  = values().length;

  static {
    PayrollDay[] days = values();

    for (int i = FIRST_DAY_OF_WEEK; i <= LAST_DAY_OF_WEEK; i++) {
      dayOfWeekToPayrollDay.put(new Integer(i), days[i-1]);
    }
  }

  static PayrollDay fromDayOfWeek(int i) {
    if (i < 1 || i > 7)
      return null;
    else 
      return dayOfWeekToPayrollDay.get(i); //auto-boxing alert
  }

  private enum PayType {
    WEEKDAY {
      @Override
      double overtimePay (int hoursWorked, double payRate) {
        return hoursWorked <= HOURS_PER_SHIFT ? 0 
          : (hoursWorked - HOURS_PER_SHIFT) * payRate / 2;
      }
    }, 
    WEEKEND {
      @Override
      double overtimePay (int hoursWorked, double payRate) {
        return hoursWorked * payRate / 2;
      }
    };

    private static final int HOURS_PER_SHIFT = 8;

    abstract double overtimePay (int hoursworked, double payRate);

    double pay (int hoursWorked, double payRate) {
      double basePay = hoursWorked * payRate;
      return basePay + overtimePay(hoursWorked, payRate);
    }
  }

}

public class StrategyEnumPatterTest {

  public static void main (String[] args) {

    if (args.length != 3) {
      System.out.println("Usage: java StrategyEnumPattern Test <int hours worked today> <double today's payrate> <day of week(Monday>");
    }

    int hoursWorked  = Integer.parseInt(args[0]);
    double payRate   = Double.parseDouble(args[1]);
    int dayOfWeek = Integer.parseInt(args[2]);

    PayrollDay day = PayrollDay.fromDayOfWeek(dayOfWeek);

    if (null != day) 
      System.out.printf("%d hours at %f per hour on %s = %f%n",
                        hoursWorked, payRate, 
                        day, day.pay(hoursWorked,payRate));
    else
      System.out.println("Bad input day of week");
    
  }

}