
/*
 * Template file for the solution to part 1
 * Use the included print statements in your code at appropriate times.
 * Do not adjust the format of the print statements.
 * Do not submit a final solution with additional print statements.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main( int argc, char **argv ) {

  // command line arguments
  if( argc == 2 ) {
      //printf("Argument's value is %s\n", argv[1]);
   }
   else if( argc > 2 ) {
      printf("Too many arguments supplied. Exiting\n");
      exit(0);
   }
   else {
      printf("Arguments is needed. Exiting.\n");
      exit(0);
   }

  // reading from file
  printf("Input file. Opening.\n");
  FILE* input_file;
  input_file = fopen(argv[1], "r");

  // writing to file
  printf("Output file. Opening.\n");
  FILE* output_file;
  output_file = fopen("average.txt","w+");

  if (NULL == input_file) {
      printf("Input file does not exist. Exiting.\n");
      exit(0);
  }

  if (output_file == NULL)
  {
      printf("Error opening the average.txt file\n");
      exit(0);
  }

  // character by character using loop.
  char line[256];

  while (fgets(line, sizeof(line), input_file) != NULL)
  {
    // student id value
    char *student_data = strtok(line, " ");
    int student_id;
    // convert char * to int
    sscanf(student_data, "%d", &student_id);

    // writing into average.txt file with student id
    fprintf(output_file,"%s ",student_data);

    // checking avaibable value for student id
    // requires student id
    printf("Checking data.\n");
    if(student_id < 2022000 || student_id > 2022099){
      //printf("Student_id value should be 2022000 ~ 2022099\n"); 
      printf("Found an invalid student id: %d. Exiting.\n",student_id); 
      exit(0);
    }

    // grade values 
    student_data = strtok(NULL, " ");
    int sum = 0;
    int count = 0;
    int average = 0;
    
    // compute averages
    printf("Computing averages.\n");

    while (student_data != NULL)
    {

      // calculate the average grade
      int grade;
      float f_avg;
      int i_avg;
      count++;

      // convert char * to int
      sscanf(student_data, "%d", &grade);

      // checking for available value for grade
      // requires student id and relevant grade
      if(grade < 0 || grade > 100){
        //printf("Grade values should be 0 ~ 100");
        printf("Found an invalid grade: id %d grade %d. Exiting.\n", count, grade);
        exit(0);
      }

      // Constraints for Any grade
      if(grade < 20) {
        printf("Correcting student %d grade %d\n",student_id,grade);
        grade = 20;
        
      }
      else if(grade > 90) {
        printf("Correcting student %d grade %d\n",student_id,grade);
        grade = 90;
      }
      // calculate sum for each grade value
      sum += grade;
      
      // students with 4 grades for each student
      if(count == 4){
        // calculate average all grade
        f_avg = (float)sum / count;
        i_avg = (int)f_avg;
        average = i_avg;
        
        // Rounded average value with integer value
        // Round Rule: (grade < g+0.5) = g, (grade >= g+0.5) = g+1
        if(f_avg < i_avg + 0.5){ 
          average = i_avg;
        }else if(f_avg >= i_avg + 0.5) {
          average = i_avg + 1;
        }
      }

      // get next grade values in a line
      student_data = strtok(NULL, " ");
    }
    
    // writing into average.txt file with average value
    fprintf(output_file, "%d\n",average);
  }
    
  // Closing the file
  printf("Input file. Closing.\n");
  fclose(input_file);
  
  printf("Output file. Closing.\n");
  fclose(output_file);

  return 0;
}

