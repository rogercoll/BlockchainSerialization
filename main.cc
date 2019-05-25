#include<iostream>
#include <fstream>
#include"BCS.pb.h"
using namespace std;


void AddTransaction(BCS::Chain::Transaction* t1,string &sender,string &reciver,double amount){
    t1->set_fromaddress(sender);
    t1->set_toaddress(reciver);
    t1->set_amount(amount);
    t1->set_hash("Here goes the hash");
}
void AddBlock(BCS::Chain::Block* b1){
    string sender = "Sara";
    string reciver = "Roger";
    double amount = 3;
    double amount2 = 23;
    AddTransaction(b1->add_transactions(),sender,reciver,amount);
    AddTransaction(b1->add_transactions(),sender,reciver,amount);
    AddTransaction(b1->add_transactions(),sender,reciver,amount);
    AddTransaction(b1->add_transactions(),sender,reciver,amount2);
    b1->set_prevhash("Here goes the previous hash");
    b1->set_txroot("Here goes the txroot hash");
}
int main(){
    BCS::Chain myblockchain;
    AddBlock(myblockchain.add_blocks());
    fstream output("myblockchain.txt", ios::out | ios::trunc | ios::binary);
    if (!myblockchain.SerializeToOstream(&output)) {
      cout << "Failed to write address book." << endl;
      return -1;
    }
}
