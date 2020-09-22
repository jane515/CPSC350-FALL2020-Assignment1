//Jane Yang
//2317614
//huayang@chapman.edu
//CPSC350-01
//Assignment 1
#include <iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<math.h>
#include<cstring>
using namespace std;

int main(int argc,char** argv)
{
  while(true)
  {
    if(argc<2)
    {
      cout << "You need to Enter an argument"<<endl;
      return -1;
    }
    else if(argc>3)
    {
      cout<<"You are only allowed to enter one file name"<<endl;
      return -1;
    }
    string firstFile = argv[1];
    string fileName = firstFile;
    //read in the file
    std::ifstream file(fileName);
    int count = 0;
    double sum = 0;
    double mean = 0;
    double varian = 0;
    //error check if the file is open
    if(file.is_open())
    {
      std::string line;
      //read each line of the file and calculate the mean and varian
      while(std::getline(file,line))
      {
        std::transform(line.begin(),line.end(),line.begin(),::tolower);
        sum += line.length();
        count++;
      }
    }
    mean = sum/count;
    //second time read through file, calculate the probability
    std::ifstream file2(fileName);
    int countA = 0;
    int countC = 0;
    int countT = 0;
    int countG = 0;
    int countAA = 0;
    int countAC = 0;
    int countAT = 0;
    int countAG = 0;
    int countCA = 0;
    int countCC = 0;
    int countCT = 0;
    int countCG = 0;
    int countTA = 0;
    int countTC = 0;
    int countTT = 0;
    int countTG = 0;
    int countGA = 0;
    int countGC = 0;
    int countGT = 0;
    int countGG = 0;
    //error check
    if(file2.is_open())
    {
      std::string line;
      char previous = ' ';
      while(std::getline(file2,line))
      {
        std::transform(line.begin(),line.end(),line.begin(),::tolower);
        double length = line.length();
        double var = pow(length-mean,2);
        varian+=var;
        //check if previous line of string have a single character left
        if(previous==' ')
        {
          for(int i = 0;i<line.size();i+=2)
          {
            if(line[i]=='a')
            {
              if(line[i+1]=='a')
              {
                countAA++;
              }
              else if(line[i+1]=='c')
              {
                countAC++;
              }
              else if(line[i+1]=='t')
              {
                countAT++;
              }
              else if(line[i+1]=='g')
              {
                countAG++;
              }
            }
            else if(line[i]=='c')
            {
              if(line[i+1]=='a')
              {
                countCA++;
              }
              else if(line[i+1]=='c')
              {
                countCC++;
              }
              else if(line[i+1]=='t')
              {
                countCT++;
              }
              else if(line[i+1]=='g')
              {
                countCG++;
              }
            }
            else if(line[i]=='t')
            {
              if(line[i+1]=='a')
              {
                countTA++;
              }
              else if(line[i+1]=='c')
              {
                countTC++;
              }
              else if(line[i+1]=='t')
              {
                countTT++;
              }
              else if(line[i+1]=='g')
              {
                countTG++;
              }
            }
            else if(line[i]=='g')
            {
              if(line[i+1]=='a')
              {
                countGA++;
              }
              else if(line[i+1]=='c')
              {
                countGC++;
              }
              else if(line[i+1]=='t')
              {
                countGT++;
              }
              else if(line[i+1]=='g')
              {
                countGG++;
              }
            }
            if(line.length()%2!=0)
            {
              previous =line[-1];
            }
            else if(line.length()%2==0)
            {
              previous = ' ';
            }
          }
        }
        //if the previus line have a single character left, combine it with the first character of the new line
        else if(previous!=' ')
        {
          for(int i = 0;i<line.size();i+=2)
          {
            if(previous=='a')
            {
              if(line[i]=='a')
              {
                countAA++;
              }
              else if(line[i]=='c')
              {
                countAC++;
              }
              else if(line[i]=='t')
              {
                countAT++;
              }
              else if(line[i]=='g')
              {
                countAG++;
              }
            }
            else if(previous=='c')
            {
              if(line[i]=='a')
              {
                countCA++;
              }
              else if(line[i]=='c')
              {
                countCC++;
              }
              else if(line[i]=='t')
              {
                countCT++;
              }
              else if(line[i]=='g')
              {
                countCG++;
              }
            }
            else if(previous=='t')
            {
              if(line[i]=='a')
              {
                countTA++;
              }
              else if(line[i]=='c')
              {
                countTC++;
              }
              else if(line[i]=='t')
              {
                countTT++;
              }
              else if(line[i]=='g')
              {
                countTG++;
              }
            }
            else if(previous=='g')
            {
              if(line[i]=='a')
              {
                countGA++;
              }
              else if(line[i]=='c')
              {
                countGC++;
              }
              else if(line[i]=='t')
              {
                countGT++;
              }
              else if(line[i]=='g')
              {
                countGG++;
              }
            }
            if(line.length()%2==0)
            {
              previous =line[-1];
            }
            else if(line.length()%2!=0)
            {
              previous = ' ';
            }
          }
        }
        //check each individual character's frequency
        for(char&c:line)
        {
          if(c=='a')
            countA++;
          else if(c=='c')
            countC++;
          else if(c=='t')
            countT++;
          else if(c=='g')
            countG++;
        }
      }
    }
    double variance = varian/count;
    double sd = sqrt(variance);
    double probA = countA/sum;
    double probC = countC/sum;
    double probT = countT/sum;
    double probG = countG/sum;
    double countBi = sum/2;
    double probAA = countAA/countBi;
    double probAC = countAC/countBi;
    double probAT = countAT/countBi;
    double probAG = countAG/countBi;
    double probCA = countCA/countBi;
    double probCC = countCC/countBi;
    double probCT = countCT/countBi;
    double probCG = countCG/countBi;
    double probTA = countTA/countBi;
    double probTC = countTC/countBi;
    double probTT = countTT/countBi;
    double probTG = countTG/countBi;
    double probGA = countGA/countBi;
    double probGC = countGC/countBi;
    double probGT = countGT/countBi;
    double probGG = countGG/countBi;
    ofstream out;
    //create an output file and write the answer to the file
    out.open("jane.txt");
    out<<"Jane Yang\n2317614\nhuayang@chapman.edu\nCPSC350-01\nAssignment 1\n";
    out<<"Sum: "<<sum<<endl;
    out<<"Mean: "<<mean<<endl;
    out<<"Variance: "<<variance<<endl;
    out<<"Standard Deviation: "<<sd<<endl;
    out<<"Relative Probability A:"<<probA<<endl;
    out<<"Relative Probability C:"<<probC<<endl;
    out<<"Relative Probability T:"<<probT<<endl;
    out<<"Relative Probability G:"<<probG<<endl;
    out<<"Relative Probability AA: "<<probAA<<endl;
    out<<"Relative Probability AC: "<<probAC<<endl;
    out<<"Relative Probability AT: "<<probAT<<endl;
    out<<"Relative Probability AG: "<<probAG<<endl;
    out<<"Relative Probability CA: "<<probCA<<endl;
    out<<"Relative Probability CC: "<<probCC<<endl;
    out<<"Relative Probability CT: "<<probCT<<endl;
    out<<"Relative Probability CG: "<<probCG<<endl;
    out<<"Relative Probability TA: "<<probTA<<endl;
    out<<"Relative Probability TC: "<<probTC<<endl;
    out<<"Relative Probability TT: "<<probTT<<endl;
    out<<"Relative Probability TG: "<<probTG<<endl;
    out<<"Relative Probability GA: "<<probGA<<endl;
    out<<"Relative Probability GC: "<<probGC<<endl;
    out<<"Relative Probability GT: "<<probGT<<endl;
    out<<"Relative Probability GG: "<<probGG<<endl;
    int sumD = 0;
    double portionA = probA*100;
    double portionC = (probC*100)+portionA;
    double portionT = (probT*100)+portionC;
    double portionG = (probG*100)+portionT;
    int numA = 1000*mean*probA;
    //calculation process provided on the assignment instruction
    for(int i =0;i<1000;i++)
    {
      double a = ((double)rand()/(double)RAND_MAX);
      double b = ((double)rand()/(double)RAND_MAX);
      double c = sqrt(-2*log(a))*cos(2*M_PI*b);
      double d = ceil(abs(sd*c+mean));
      sumD+=d;
      if(d<=0)
      {
        cout<<"a line is 0!"<<endl;
      }
      std::string addline;
      for(int i =0;i<d;i++)
      {
        int ran = rand()% 101;
        if(ran <= portionA)
        {
          addline.append(1,'a');
          numA-=1;
        }
        else if(ran <= portionC)
        {
          addline.append(1,'c');
        }
        else if(ran <= portionT)
        {
          addline.append(1,'t');
        }
        else
        {
          addline.append(1,'g');
        }
      }
      out<<addline<<endl;
    }

    out.close();
    cout<<"Answer written to output file completely."<<endl;
    //check if the user want to input another file
    while(true)
    {
      char answer;
      cout<<"Do you want to process another file? 'y' or 'n'"<<endl;
      cin>>answer;
      if(answer=='n'||answer=='N')
      {

        return 0;
      }
      else if(answer=='y'||answer=='Y')
      {
        std::string fileN;
        cout<<"Name of the new file: "<<endl;
        cin>>fileN;
        firstFile = fileN;
        break;
      }
    }
  }
}
