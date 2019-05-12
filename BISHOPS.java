
import java.util.*;
import java.math.*;

class bishops  {
    public static void main(String []args) {
        Scanner scan = new Scanner(System.in);
        BigInteger t2 = new BigInteger("2");
        while(scan.hasNext()) {
            BigInteger n = new BigInteger(scan.nextLine());
            if (n.equals(BigInteger.ONE)) 
                System.out.println("1");
            else
                System.out.println(n.add(n).subtract(t2));
        }
    }
}
