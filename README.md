# Curl_assignment

The code has two classes 

1) UserInfo which is a derived class of the class curl, this stores information of users such as account number/name/password/account balance and also has some member functions that enable balance check/ withdrawl/ deposit features.

2) Another class is of bank that called curl which is parent class to above class and has member functions to cut or add balance upon withdrawl or deposit respectively, it has data members balance that is the money bank has and information of its users

To use this program, run it will ask you to enter account number which is being used as the primary identification of every account.

Upon entering the password if it is correct you will have successfully logged in and a menu will appear enabling user to choose among withdrawl/deposit/check balance

If deposit/withdrawl is chosen it will ask you the amount and if the transaction is possible it will show a successful message.
