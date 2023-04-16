import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        HashMap<String, String> map = new HashMap<String, String>();

        for(int i = 0;i < N;i++)
        {
            String a,b;
            a = scanner.next();
            b = scanner.next();
            map.put(a,b);
        }
        int K = scanner.nextInt();
        for(int i = 0;i < K;i++)
        {
            int num = scanner.nextInt();
            Vector v = new Vector(num,3);
            Boolean possible = true;
            for(int j = 0;j < num;j++)
            {
                String pos = scanner.next();
                if(map.containsKey(pos))
                    v.add(map.get(pos));
                else
                    possible = false;
            }
            if(possible)
            {
                for(int j = 0; j < v.size();j++)
                {
                    System.out.print(v.get(j) + " ");
                }
                System.out.print("\n");
            }
            else
            {
                System.out.println("YOU DIED");
            }
        }

    }
}
