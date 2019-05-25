#include<iostream>
#include <fstream>
#include"BCS.pb.h"
using namespace std;

void VerifyBlockchain(const BCS::Chain& totest){
  cout<<"Verifying blockchian"<<endl;
  for(int i = 0; i < totest.blocks_size(); i++){
    const BCS::Chain::Block& b = totest.blocks(i);
    cout<<"Block: "<<i<<endl;
    cout<<"   Txroot: "<<b.txroot()<<endl;
    cout<<"   Num of Transactions: "<<b.transactions_size()<<endl;
    for(int j = 0; j < b.transactions_size(); j++){
      const BCS::Chain::Transaction& t = b.transactions(j);
      cout<<"      Transaction: "<<j<<endl;
      cout<<"      FromAddress: "<<t.fromaddress()<<endl;
      cout<<"      ToAddress: "<<t.toaddress()<<endl;
      cout<<"      Amount: "<<t.amount()<<endl;
    }
  }
}

int main(int argc, char* argv[]){
  // Verify that the version of the library that we linked against is
  // compatible with the version of the headers we compiled against.
  GOOGLE_PROTOBUF_VERIFY_VERSION;
  if (argc != 2) {
      cout << "Usage:  " << argv[0] << "BLOCKCHAIN_FILE" << endl;
      return -1;
  }
  BCS::Chain BCtoverify;
  {
      // Read the existing address book.
      fstream input(argv[1], ios::in | ios::binary);
      if (!BCtoverify.ParseFromIstream(&input)) {
        cerr << "Failed to parse blockchain." << endl;
        return -1;
      }
  }
  VerifyBlockchain(BCtoverify);
}
