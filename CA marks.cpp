//Level 200 Computer Engineering CA Mark Calculation
#include <iostream.h>
#include <iomanip.h>


float max(float , float);
float min(float , float);
float mark_percentage(float, float);

int main()
{
    float mark[7],remains[5], sum_rem_marks = 0, CA_MARK = 0;
    float best_mark, worst_mark, last_mark;
    float best_mark_percentage, worst_mark_percentage, last_mark_percentage;
    int i, j;
    // We start by initialising the table with marks
    for( i = 0; i < 7; i++)
    {
         cout << "Enter CA mark " << i + 1 << " : ";
         cin >> mark[i];
         while( mark[i] < 0 || mark[i] > 15 )
         {
                cout << "Please enter a valid CA mark between 0 and 15 : ";
                cin >> mark[i];
         }
    }
    last_mark = mark[6];
    last_mark_percentage = mark_percentage( last_mark, 15);
    best_mark = max( mark[0],mark[1]);
    worst_mark = min( mark[0], mark[1]);
    // Lets look for the best mark and the worst mark 
    for( i = 2; i < 6; i++) 
    { 
          best_mark = max( best_mark,mark[i]);
          worst_mark = min( worst_mark, mark[i]);
    }
    
    best_mark_percentage = mark_percentage( best_mark, 50);
    
    //Lets discard the best mark since we've stored its value
    
     for(i = 0; i < 6; i++)
    {
        if( mark[i] == best_mark)
        {
              for( j = i; j < 6; j++)
              {
                   mark[j] = mark[j+1];
              }
        }         
    }
    
    //We now have five marks remaining
    //We've got the two values of maximum and minimum marks
    //Lets now discard the worst mark.We don't want the student to fail not so?

    for(i = 0; i < 5; i++)
    {
        if( mark[i] == worst_mark)
        {
              for( j = i; j < 5; j++)
              {
                   mark[j] = mark[j+1];
              }
        }         
    }
    

    
    //Leavig this loop we've got an array without the worst mark of the five remaining
    //Our array now has four marks. Lets look for the worst of these 4. It is this worst that takes 5% of the CA mark
                    
    worst_mark = min( mark[0], mark[1]);
    for(i = 2; i < 4; i++)
    {
         worst_mark = min( worst_mark, mark[i]);
    }
    //We now find the value it occupies as part of the CA mark 
    
    worst_mark_percentage =  mark_percentage( worst_mark, 5);
    
    //Lets discard this second worst mark since we've stored its value 
    
    for(i = 0; i < 4; i++)
    {
        if( mark[i] == worst_mark)
        {
              for( j = i; j < 4; j++)
              {
                   mark[j] = mark[j+1];
                   cout << mark[j] << endl;
              }
        }         
    }
    //We now have only three marks in our array. These marks take 10% of the CA each.
    //I started discarding marks from the array because of this loop. If I had left them and tried to use the if loop
    //such that any mark diferent from the best and worst be added to the sum of remaining marks, there would be a problem.
    //Which problem? If the student had 15 in all the tests, then the current mark will always be equal to the best mark.
    //So we will be leaving the for loop with a zero sum of remaining marks.
   
    for( i = 0; i < 3; i++)
    {
             sum_rem_marks = sum_rem_marks + mark_percentage(mark[i], 10);     
    }
    cout << sum_rem_marks << endl;
    CA_MARK = sum_rem_marks + worst_mark_percentage + best_mark_percentage + last_mark_percentage;
    cout <<"This student's CA mark is " << CA_MARK*30/100 << endl;
    //And tada! we got our CA mark
                       
    system("pause");
    return 0;
}


inline float max(float a, float b)
{
      float max;
      max = a;
      if(b>a)
      max = b;
      return max;
}

inline float min(float a, float b)
{
      float min;
      min = a;
      if(b<a)
      min = b;
      return min;
}

inline float mark_percentage(float mark, float percentage)
{
    float  End_mark;
    End_mark = mark * percentage / 15;
    return End_mark;
} 
