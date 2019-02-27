import java.util.*;

public class Sort {

  public static void main (String[] args) {

    int[] data = {2,1,3,4,8,5,7,6};
    ArrayList<Integer> data2 = new ArrayList<Integer>();
    data2.add(2);
    data2.add(1);
    data2.add(3);
    data2.add(4);
    data2.add(8);
    data2.add(5);
    data2.add(7);
    data2.add(6);

    insertSort(data2);

    for (int i = 0; i < data2.size(); i++) {

      System.out.println(data2.get(i));
    }
  }

  public static void sort (int[] data) {

    for (int i = 0; i < data.length; i++) {

      int min = data[i];
      int index = i;

      for (int k = i; k < data.length; k++) {

        if (data[k] < min) {

          min = data[k];
          index = k;
        }
      }

     int placeholder = data[i];
     data[i] = min;
     data[index] = placeholder;
    }
  }

  public static void insertSort (ArrayList<Integer> data) {

    for (int i = 0; i < data.size(); i++) {

      int index = i;

      for (int k = i; k > -1; k--) {

        if (data.get(k) > data.get(i)) {

          index = k;
        }
      }

      data.add(index, data.remove(i));
    }
  }
}
