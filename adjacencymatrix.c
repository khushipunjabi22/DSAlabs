int main() {
 int size;
 printf("Enter number of nodes:");
 scanf("%d", &size);
 int arr[size][size];
 int choice, exit=1,m,n;
 char p,q;
 int i,j;
 for(i = 0;i<size;i++){
 for(j=0;j<size;j++){
 arr[i][j] = 0;
 }
 }
 while(exit == 1){
 printf("\n\nEnter an Option\n1.Add an Directed edge\n2.Add an Undirected edge\n3. Show
Adjacency Matrix\n4. Quit\n");
 scanf("%d", &choice);
 switch(choice){
 case 1:
 printf("Enter the name of node(A to Z) from which you want to add an directed edge to other
node(A to Z):");
 scanf(" %c %c", &p,&q);
 m = p - 65;
 n = q - 65;
 if(m>=size || n >=size || m == n){
 printf("\nCannot add an edge\n");
 }
 else{
 arr[m][n] = 1;
 printf("Successfully added edge from %c to %c\n", p, q);
 }
 break;
 case 2:
 printf("Enter the name of node(A to Z) from which you want to add an directed edge to other
node(A to Z):");
 scanf(" %c %c", &p,&q);
 m = p - 65;
 n = q - 65;
 if(m>=size || n >=size || m == n){
 printf("\nCannot add an edge\n");
 }
 else{
 arr[m][n] = 1;
 arr[n][m] = 1;
 printf("Successfully added edge between %c and %c\n", p, q);
 }
 break;
 case 3:
 printf("The adjacency matrix is:\n");
 printf(" ");
 for(j=0;j<size;j++){
 printf("%c ", j+65);
 }
 printf("\n");
 for(i=0;i<size;i++){
 printf("%c ", i+65);
 for(j=0;j<size;j++){
 printf("%d ", arr[i][j]);
 }
 printf("\n");
 }
 break;
 case 4:
 exit = 0;
 break;
 }
 }
 return 0;
}
