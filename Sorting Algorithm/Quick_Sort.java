import java.util.Scanner;

import static java.lang.Math.random;

public class Quick_Sort {

    public static void quick_sort(int[] arr,int low,int high){
        if(low < high){
            int pi = partition(arr,low,high);

            quick_sort(arr,low,pi-1);
            quick_sort(arr,pi+1,high);
        }
    }

    private static int partition(int[] arr, int low, int high) {

        //randamized quick sort (randomly taken pivot)
        //it reduce chance of O(n^2)
        int pi = low + (int)(Math.random() % (high - low + 1));
        int t = arr[pi];
        arr[pi] = arr[high];
        arr[high] = t;

        int pivot = arr[high];
        int i = low - 1;

        for(int j=low;j<high;j++){
            if(arr[j] < pivot){
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;

        return i+1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n;
        n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0;i<n;i++)
            arr[i] = sc.nextInt();

        quick_sort(arr,0,arr.length-1);

        for(int i : arr){
            System.out.print(i + " ");
        }
    }
}
