#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main()
{
     int random_num = rand() % 90 + 10;
    random_num *= 5;
    int quotient = 2535 / random_num;
    int remainder = quotient % 25;
    if (remainder < 10)
        remainder += 15;
    int n = remainder; // size of matrix
    n=2;
cout<<" Size of the Matrix is  "<<n<<endl;
    // Populate matrix with random values
    int **matrix = new int*[n];
    for (int i=0; i<n; i++)
    {
        matrix[i] = new int[n];
        for (int j=0; j<n; j++)
            matrix[i][j] = rand() % 100;
    }

    // Save matrix to text file
    ofstream outfile;
    outfile.open("matrix.txt");
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            outfile << matrix[i][j] << " ";
        outfile << endl;
    }
    outfile.close();

cout<<" The Value of the matrix that filled in the files with random values  "<<endl<<endl;

  for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }



    // Create child processes
    pid_t pid;
    for (int i=0; i<n; i++)
    {
        pid = fork();
        if (pid == 0)
        {
            // Child process: multiply row of matrix and save to text file
            int *result = new int[n];
            for (int j=0; j<n; j++)
            {
                result[j] = 0;
                for (int k=0; k<n; k++)
                    result[j] += matrix[i][k] * matrix[k][j];
            }
            ofstream outfile;
            outfile.open("result_" + to_string(i) + ".txt");
            for (int j=0; j<n; j++)
                outfile << to_string(result[j]) << " ";
            outfile.close();
            exit(0);
        }
        else if (pid == -1)
        {
            cout << "Failed to fork a child process" << endl;
            exit(1);
        }
    }

    // Wait for child processes to finish
    for (int i=0; i<n; i++)
         wait(NULL);

    // Read result files and display resultant matrix
    int **result_matrix = new int*[n];
    for (int i=0; i<n; i++)
        result_matrix[i] = new int[n];
    for (int i=0; i<n; i++)
    {
        ifstream infile;
        infile.open("result_" + to_string(i) + ".txt");
        for (int j=0; j<n; j++)
            infile >> result_matrix[i][j];
        infile.close();
    }
    cout << "Resultant matrix:" << endl;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cout << result_matrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}
