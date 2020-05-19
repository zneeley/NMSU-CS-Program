import java.util.Random;

public class Cs372hw3 {

    public static void main(String[] args) {
        // init
        int numbers[] = {100, 1000, 10000, 100000, 1000000};
        for (int j = 0; j < numbers.length; j++){
            long startTime = System.nanoTime();
            int Array[] = new int[numbers[j]];
            int size = Array.length;
            Random random = new Random();

            // Fill array with random numbers
            for (int i = 0; i < size; i++) {
                Array[i] = random.nextInt(1000000);
            }

            // Sort the array
            QuickSort(Array, 0, size-1);
            long endTime   = System.nanoTime();
            long totalTime = endTime - startTime;
            System.out.println("QuickSort Array runtime with size of " + numbers[j] + ": " + totalTime + " nano seconds");
        }
        
        // Preform Quick sort with a median pivot
        for (int j = 0; j < numbers.length; j++){
            long startTime = System.nanoTime();
            int Array[] = new int[numbers[j]];
            int size = Array.length;
            Random random = new Random();

            // Fill array with random numbers
            for (int i = 0; i < size; i++) {
                Array[i] = random.nextInt(1000000);
            }

            // Sort the array
            QuickSortMedian(Array, 0, size-1);
            long endTime   = System.nanoTime();
            long totalTime = endTime - startTime;
            System.out.println("QuickSort Median Pivot Array runtime with size of " + numbers[j] + ": " + totalTime + " nano seconds");
        }
    }

    // Preform a quicksort on the incoming array
    public static void QuickSort(int[] A, int p, int r) {
        if (p < r) {
            int q = Partition(A, p, r);
            QuickSort(A, p, q-1);
            QuickSort(A, q+1, r);
            
        }
    } 
    
    // Partition an incoming array 
    public static int Partition(int[] A, int p, int r) {
        int x = A[r]; // select the pivot element
        int i = p-1;
        
        for (int j = p; j < r; j++){
            if (A[j] <= x){
                i++;
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
        
        int temp = A[i+1];
        A[i+1] = A[r];
        A[r] = temp;
        
        return i+1;
    }
    
    // Preform a quicksort with median pivot on the incoming array
    public static void QuickSortMedian(int[] A, int p, int r) {
        if (p < r) {
            int q = PartitionMedian(A, p, r);
            QuickSort(A, p, q-1);
            QuickSort(A, q+1, r);
            
        }
    } 
    
    // Partition with median pivot an incoming array 
    public static int PartitionMedian(int[] A, int p, int r) {
        int x = A[(p+r)/2]; // select the pivot element
        int i = p-1;
        
        for (int j = p; j < r; j++){
            if (A[j] <= x){
                i++;
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
        
        int temp = A[i+1];
        A[i+1] = A[r];
        A[r] = temp;
        
        return i+1;
    }
}
