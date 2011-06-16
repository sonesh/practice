import java.util.Arrays;

public class Anagram {

  public static void main (String args[]) {

    if (args.length != 2) {
      System.out.println("Usage: java Anagram String1 String2");
      System.exit(0);
    }

    char[] s1 = args[0].toCharArray();
    char[] s2 = args[1].toCharArray();

    Arrays.sort(s1);
    Arrays.sort(s2);

    if (Arrays.equals(s1, s2))
      System.out.println(args[0] + " and " + args[1] + " are anagrams");
    else
      System.out.println(args[0] + " and " + args[1] + " are not anagrams");

  }

}