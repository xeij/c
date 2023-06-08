public class main {


public static void sorter(int array[], int size){

int i,j,temp;
for(i=0; i<size-1; i++){
    for(j=0; j<size-i-1; j++){
        
        if(array[j] > array[j+1]){
            temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
            }
        }
    }
}

public static void main(String[] argv){
    
    int array[] = {1,3,2,5,4};
    int size = array.length;
    
    System.out.print("Original Array: ");
    for(int c : array){
System.out.print(c + " ");
    }

System.out.println();
sorter(array, size);

System.out.print("Sorted Array: ");
for(int c : array){
    System.out.print(c+ " ");
        }       

    }  
}
    