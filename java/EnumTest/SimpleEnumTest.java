enum SimpleEnum {
  ONE, TWO;
}

public class SimpleEnumTest {

  public static void main (String[] args) {
    for (SimpleEnum simpleEnum: SimpleEnum.values())
      System.out.println(simpleEnum);
  }

}

