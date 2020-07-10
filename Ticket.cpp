#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class passenger
{
protected:
	string src,des;
	string name[10];
    int exceed,ch,cy,t,age[5],bill,n,c,a[50],inc;
    double aadhar[5];
    static int sc,asl,nsl,sc_seat,asl_seat,nsl_seat;
public:
	passenger();
	
    void src_des()
    {
		cout<<"\tWELCOME TO RAILWAY RESERVATION SYSTEM";
		cout<<"\n1.Erode<->Chennai\n2.Coimbatore<->Chennai\n3.Kanyakumari<->Chennai\nEnter your choice "; 
        cin>>ch;
        cout<<"Enter your source station ";
        cin>>src;
        cout<<"Enter your destination station ";
        cin>>des;
    }
    void time()
    {
        switch(ch)
        {
        	case 1:
        	if(src=="erode"||src=="ERODE")
        	{
        		cout<<"\nSelect your timing\n1 6.00\n2 11.00\n3 18.00\n";
        		cin>>t;
        	}
        	else if(src=="chennai"||src=="CHENNAI")
        	{
        		cout<<"\nSelect your timing\n1 10.00\n2 13.00\n3 22.00\n";
        		cin>>t;
        	}
        	else
        	{
        		cout<<"\nINVALID STATION";
        		exceed=1;
        	}
        	break;
        	case 2:
        	if(src=="coimbatore"||src=="COMIBATORE")
        	{
        		cout<<"\nSelect your timing\n1 6.00\n2 11.00\n3 18.00\n";
        		cin>>t;
        	}
        	else if(src=="chennai"||src=="CHENNAI")
        	{
        		cout<<"\nSelect your timing\n1 10.00\n2 13.00\n3 22.00\n";
        		cin>>t;
        	}
        	else
    		{
        		cout<<"\nINVALID STATION";
        		exceed=1;
    		}
        	break;
        	case 3:
        		if(src=="kanyakumari"||src=="KANYAKUMARI")
        	{
        		cout<<"\nSelect your timing\n1 6.00\n2 11.00\n3 18.00\n";
        		cin>>t;
        	}
        	else if(src=="chennai"||src=="CHENNAI")
        	{
        		cout<<"\nSelect your timing\n1 10.00\n2 13.00\n3 22.00\n";
        		cin>>t;
        	}
        	else
        	{
        		cout<<"\nINVALID STATION";
        		exceed=1;
        	}
        	break;
        } 
	}
	void book(int x=550,int y=420,int z=360)
	{
		cout<<"1.a/c sleeper \n 2.non a/c sleeper \n 3.second class \nenter the choice";
         cin>>cy;
         cout<<"Enter the no.of tickets ";
		cin>>n;
        switch(cy)
          {
                   case 1:
                   if(n>asl)
                   {
                   	 exceed=1;
                   	 break;
                   }
                    bill+=x*n;
                    asl-=n;
                  a[inc]=asl_seat+1;
                    inc++;
                  break;
                   case 2:
                    if(n>nsl)
                    {
                    	exceed=1;
                    	break;
                    }
                         bill+=y*n;
                         nsl-=n;
                        c=1;
                      a[inc]=nsl_seat+1;
                      inc++;
                       break;
                   case 3:
                   if(n>sc)
                   {
                   	exceed=1;
                   	break;
                   }
                        bill+=n*z;
                        sc-=n;
                        c==2;
                       a[inc]=sc_seat+1;
                       inc++;
                        break;
          
	}
  }

	void details()
	{

		for(int i=1;i<=n;i++)
		{
			cout<<"Enter details for passenger number "<<i;
			cout<<"\nEnter Name : ";
			cin>>name[i];
			cout<<"\nEnter age : ";
			cin>>age[i];
			cout<<"\nEnter your aadhar number ";
			cin>>aadhar[i];
		}
	}
  void display()
  {

  	cout<<"\nNumber of travellers "<<n;
  	for(int i=1;i<=n;i++)
  	{
  	   cout<<"\n Name : "<<name[i];
  	   cout<<"\nAge :"<<age[i];
  	}
    if(c==0)
     cout<<"\nClass: a/c sleeper";
    else if(c==1)
    	cout<<"\nClass :Non a/c sleeper";
    else
    cout<<"\nClass:second class ";
    cout<<"\nTime :";
    if(src=="chennai"||src=="CHENNAI")
    {
    	switch(t)
    	{
    		case 1:
    		cout<<"6.00";
    		break;
    		case 2:
    		cout<<"11.00";
    		break;
    		case 3:
    		cout<<"18.00";
    		break;
    	}
    }
    else
    {
    	switch(t)
    	{
    		case 1:
    		cout<<"6.00";
    		break;
    		case 2:
    		cout<<"11.00";
    		break;
    		case 3:
    		cout<<"18.00";
    		break;
    	}

    }
    cout<<"\nBill amount : "<<bill;
    cout<<"\nremaining seats :\nIn A/C Sleeper :"<<asl<<"\nIn Non A/C Sleeper :"<<nsl<<"\n In Second class :"<<sc;

  }
  friend void seat(passenger o,int a[],int inc);
};
int passenger::sc=100;
int passenger::asl=100;
int passenger::nsl=100;
int passenger::sc_seat=0;
int passenger::nsl_seat=0;
int passenger::asl_seat=0;

class goods:virtual protected passenger
{
 protected:
     string name;
       int total, items,c,x,y,z;
       static int coach;
 public:
      void details()
      {
            
             total=0;
            cout<<"enter the name";
            cin>>name;
             cout<<" Choose the types of materials\n";
            cout<<"1.raw materials\n2.food materials\n3.fossil fuels \nenter the choice";
               cin>>c;
            cout<<"\nHow many coaches you need ?";
            cin>>items;
         }
         void book(int x=250,int y=150,int z=50)
         {
            switch(c)
             {
              case 1:
              if(items>coach)
              	exceed=1;
                   total+=items*x;
                   coach=coach-items;

                    break;
              case 2:
              if(items>coach)
              	exceed=1;
                  total+=items*y;
                   coach=coach-items;
                    break;
             case 3:
             if(items>coach)
              	exceed=1;
                  total+=items*z;
                   coach=coach-items;
                    break;

             }


      }
         void display()
         {
         	cout<<"\nName of user : "<<name;
         	     if(c==1)
                    cout<<"\nMaterials : Raw";
                else if(c==2)
                     cout<<"\nMaterials : Food";	
                else
                	cout<<"\nMaterial : Fossil fuels";
                    cout<<"\ntotal cost is "<<total;
                    cout<<"\nremaining coaches are "<<coach;
         }

};
int goods::coach=100;


class railway:protected goods
{
protected:
      int c;
      char yn,cr;
public:
      void choice()
      {
            while(cr!='5')
            {
             cout<<"\nBookings tickets \n1.passenger train\n2.goods rain";
             cout<<"\nEnter the choice ";
             cin>>c;
             exceed=0;
             switch(c)
             {
              case 1:
              src_des();
               time();
               if(exceed==1)
               	break;
               book();
               if(exceed==1)
               {
               	cout<<endl<<n<<" tickets are not available try out in anoter class\n";
               	break;
               }
               details();
               display();
               cout<<"\nDo you want to know your seat position (y/n) ";
               cin>>yn;
               if(yn=='y')
               {
               	passenger p;
               seat(p,a,inc); 

                }

              break;
            case 2:
                 src_des();
                 time();
                 if(exceed==1)
               	break;
               goods::details();
               goods::book();
               if(exceed==1)
               {
               	cout<<"\nSorry coaches are filled";
               	break;
               }
               goods::display();
                
                  break;
             


            }
            cout<<"\nEnter 5 to exit or press any key to exit";
            cin>>cr;
            if(cr=='5')
            	cout<<"\nTHANK YOU FOR VISITING";
        }  
    }
};
void seat(passenger o,int a[],int inc)
{
  int rem,i,quo;
  for (int i = 0; i < inc; ++i)
  {
  rem=a[i]%4;
  quo=a[i]/2;
  if(quo==0)
  {
  if(rem==0||rem==1)
  	cout<<a[i]<<" is a window seat\n";
  else if(rem==2)
  	cout<<a[i]<<" is a middle seat\n";
  else 
  	cout<<a[i]<<" is an alise seat\n";
  }
  if(quo==1)
  {
  if(rem==0||rem==1)
  	cout<<a[i]<<" is a window seat\n";
  else if(rem==3)
  	cout<<a[i]<<" is a middle seat\n";
  else 
  	cout<<a[i]<<" is an alise seat\n";
  	
  }
}
}
inline passenger::passenger()
	{   c=0;
		exceed=0;
		inc=0;
		
	}


int main()
{
	int i;
	char ch;
  railway r[20];
  cout<<"\nPress 0 to exit the whole page or press any key";
  cin>>ch;  
  while(ch!='0')
  {
  	r[i].choice();
  	i++;
  	cout<<"\nPress 0 to exit the whole page or press any key";
  	cin>>ch;
  }
  
  

}

