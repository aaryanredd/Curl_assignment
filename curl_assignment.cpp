#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class curl                                                                      // Bank class
{
    public:
    
    bool bank_available(ll wd_amt)                                              // To check if bank has money enough to make desired transactions
    {
        return wd_amt <= total_bal?true:false;                                  
    }
    
    void bank_cut_bal(ll wd_amt)                                                // To deduct money from bank's balance in case of withdrawl
    {
        total_bal-=wd_amt;
        transactions++;                                                         // Incrementing transactions
    }
    
    void bank_add_bal(ll dp_amt)                                                // To add money in to bank's balance in case of deposit
    {
        total_bal+=dp_amt;                                                      
        transactions++;
    }
    
    private:
    
    unordered_map<ll,ll>acc_bal;                                                // Map to keep record of UserInfo objects corresponding to account number
    
    ll transactions=0;                                                          // To keep record of number of transactions that occurred
    
    ll total_bal=100000000;                                                     // Money that bank has which is initially 100000000
}curl;

class UserInfo : public curl                                                    // UserInfo class that holds information of user and is derived from curl class to access its member functions
{
    public:
    
    string name;                                                                // Name of account holder
    
    void wd()                                                                   // To withdraw money from user's account                                                               
    {
        ll wd_amt;
        cout<<"Enter amount to be withdrawn: ";                         
        cin>>wd_amt;
        if(wd_amt<=balance && bank_available(wd_amt))
        {
            cout<<"Money withdrawn."<<"\n";
            bank_cut_bal(wd_amt);
            balance-=wd_amt;
        }
        else
            cout<<"Sorry you can't withdraw"<<"\n";
    }
    
    void dp()                                                                   // To deposit money into user's account
    {
        ll dp_amt;
        cout<<"Enter amount to be deposited: ";
        cin>>dp_amt;
        balance+= dp_amt;
        bank_add_bal(dp_amt);
        cout<<"Entered amount has been deposited."<<"\n";
    }
    
    void cb()                                                                   // To check balance
    {
        cout<<"Your balance is: "<<balance<<"\n"; 
    }
    
    bool login()                                                                // To verufy login by user
    {
        string in_pass;
        cout<<"Enter password: ";
        cin>>in_pass;
        if(in_pass==pass)
            return true;
        else
            cout<<"Login failed"<<"\n";
        return false;
    }
    
    ll acc_no;                                                                  // account number of account holder
    
    private:
    string pass="aaryan";                                                       // password for login by user              
    ll balance=100000;                                                          // balance of user initially put zero  
};

unordered_map<ll,UserInfo>mp;                                                   // map to store info of account number and corresponding objects

void menu()                                                                     // This is the main menu the user will see
{
    char ch='n';
    do{
        ll acc_no;
        cout<<"Enter your account number: ";
        cin>>acc_no;
        if(mp.find(acc_no)==mp.end())
            cout<<"Enter a valid account number"<<"\n";
        else 
        {   
            UserInfo &acc= mp[acc_no];
            if(acc.login())
            {
                cout<<"Enter your choice"<<"\n";
                cout<<"1. Withdraw"<<"\n";
                cout<<"2. Deposit"<<"\n";
                cout<<"3. Check balance?"<<"\n";
                ll a;
                cout<<"Your choice: ";
                cin>>a;
                switch(a)
                {
                    case 1: acc.wd();
                    break;
                    case 2: acc.dp();
                    break;
                    case 3: acc.cb();
                    break;
                    default: cout<<"Invalid input!";
                }
            }
        }
        cout<<"Enter 'y' to re-login, else 'n' "<<"\n"; 
        cout<<"Your choice: ";
        cin>>ch;
    }while(ch=='y');
}

int main()
{
    UserInfo ob1,ob2;                                                           // Declaring the users because this code does'nt support adding a user
    ob1.acc_no=1;                   
    ob2.acc_no=2;
    mp[1]=ob1;
    mp[2]=ob2;
    menu();
    return 0;
}