#include<iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;
class MathProblem{
	private:
		int n1,n2,d1,d2,correct_n,correct_d,user_n,user_d;
		char opr;
		bool isCorrect;
	public:
		void setProblem()
		{
			n1=rand()%10+1;
			d1=rand()%10+1;
			n2=rand()%10+1;
			d2=rand()%10+1;
			opr=rand()%4+1;
			user_n=0;
			user_d=0;
			isCorrect=false;
			if(opr==1)
			{
				correct_n=d2*n1+n2*d1;
				correct_d=d1*d2;
				int comm_factor=GCD(correct_n,correct_d);
				if(comm_factor==1)
		        {
		        }
		        else
		        {
		            correct_n/= comm_factor;
			        correct_d/= comm_factor;
		        }
			}
			if(opr==2)
			{
				correct_n=d2*n1-n2*d1;
				correct_d=d1*d2;
				int comm_factor=GCD(correct_n,correct_d);
				if(comm_factor==1)
		        {
		        }
		        else
		        {
		            correct_n/= comm_factor;
			        correct_d/= comm_factor;
		        }
			}
			if(opr=3)
			{
				correct_n=n1*n2;
				correct_d=d1*d2;
				int comm_factor=GCD(correct_n,correct_d);
				if(comm_factor==1)
		        {
		        }
		        else
		        {
		            correct_n/= comm_factor;
			        correct_d/= comm_factor;
		        }
			}
			if(opr==4)
			{
				correct_n=n1*d2;
				correct_d=d1*n2;
				int comm_factor=GCD(correct_n,correct_d);
				if(comm_factor==1)
		        {
		        }
		        else
		        {
		            correct_n/= comm_factor;
			        correct_d/= comm_factor;
		        }
			}
		}
		int GCD(int a, int b)
	    {
		    int gcd=1;
		    for (int i=2;i<a && i<b;i++)
		    {
			    if (a%i ==0 && b%i==0)
			    {
				    gcd=i;
			    }
		    }
	        return gcd;
	    }
		void displayProblem()
		{
		    if(opr==1)
		    {
				cout<<n1<<"/"<<d1<<" + "<<n2<<"/"<<d2<<endl;
			}
			if(opr==2)
			{
				cout<<n1<<"/"<<d1<<" - "<<n2<<"/"<<d2<<endl;
			}
			if(opr==3)
			{
				cout<<n1<<"/"<<d1<<" * "<<n2<<"/"<<d2<<endl;
			}
			if(opr==4)
			{
				cout<<n1<<"/"<<d1<<" ÷ "<<n2<<"/"<<d2<<endl;
			}
		}
		int askUserForAnswer()
		{
			cout<<endl<<"Enter Your Answer Numerator: ";
			cin>>user_n;
			cout<<"Enter Your Answer Denominator: ";
			cin>>user_d;
			if(user_n==correct_n && user_d==correct_d)
			{
				isCorrect=true;
				cout<<endl<<"Your Answer is Correct"<<endl;
				cout<<"Answer is: "<<user_n<<"/"<<user_d<<endl;
				return 1;
			}
			else
			{
				isCorrect=false;
				cout<<endl<<"Your Answer is Wrong"<<endl;
				cout<<"Correct Answer is: "<<correct_n<<"/"<<correct_d<<endl;
				return 0;
			}
		}
};

int main()
{
	srand(time(0));
	MathProblem obj[5];
	float percentage;
	float x=0,y=0;
	for(int i=0;i<5;i++)
	{
		obj[i].setProblem();
	}
	for(int i=1;i<=5;i++)
	{
		cout<<"Problem "<<i<<" : ";
		obj[i].displayProblem();
	}
	for(int i=1;i<=5;i++)
	{
		cout<<endl<<"Problem "<<i<<" :";
		x=x+1;
	    y+=obj[i].askUserForAnswer();
	}
	percentage=(y*100)/x;
	
	cout<<endl<<"Total Correct Answer: "<<percentage<<"%"<<endl;
}


