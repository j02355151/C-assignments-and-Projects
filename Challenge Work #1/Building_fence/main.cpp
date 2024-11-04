#include<iostream>
#include<string>
using namespace std;
int main()
{
int totalPosts,feetBetweenPosts,minimumFeetBetweenSigns,count,feetDistance=0,signsToOrder=0;
string fence="";
// prompt for total number of posts , number of feets between posts and
// the minimum feet between signs
cout<<"How many posts do you want to use?"<<endl;
cin>>totalPosts;
cout<<"How many feet between posts?"<<endl;
cin>>feetBetweenPosts;
cout<<"What is the minimum distance between signs (in feet)?"<<endl;
cin>>minimumFeetBetweenSigns;
// build fence(string)
for(int i=0;i<totalPosts;i++)
{
// add a post
fence+="|";
// avoid adding feets after last post
if(i!=totalPosts-1)
{
// add feets and sings between two posts
for(int j=0;j<feetBetweenPosts;j++)
{
// if current distance from previous sign is greater than or equal to
// minimumFeetBetweenSigns and the current position is not adjcent to a post
// add a sign to string
if(feetDistance>=minimumFeetBetweenSigns && (j!=0 && j!=feetBetweenPosts-1))
{
fence+="S";
feetDistance=0; // reset current distance to 0
signsToOrder++; // keep track the how many signs are added
}
// otherwise, add a feet to string
else
{
fence+="-";
feetDistance++; // increment the current distance from previous sign by 1
}
}
}
}
// finally, print the string fence
cout<<fence<<endl;
// print the total sings to be ordered
cout<<"Total Signs: "<<signsToOrder;
return 0;
}
