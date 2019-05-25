# BlockchainSerialization


For making cc of proto => protoc --cpp_out=. BCS.proto 

g++ -std=c++11 BCS.pb.cc verifyingBlockchain.cc -lprotobuf
g++ -std=c++11 BCS.pb.cc main.cc -lprotobuf
