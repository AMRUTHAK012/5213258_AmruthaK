/*
* Complete the 'truckTour' function below.
*
* The function is expected to return an INTEGER.
* The function accepts 2D_INTEGER_ARRAY petrolpumps as parameter.
*/
int truckTour(int petrolpumps_rows, int petrolpumps_columns, int**
petrolpumps) {
 int start_index=0;
 long long current_petrol=0;
 for(int i=0;i<petrolpumps_rows;i++){
 current_petrol+=petrolpumps[i][0]-petrolpumps[i][1];
 if(current_petrol<0){
 start_index=i+1;
 current_petrol=0;
}
 }
 return start_index;
}
