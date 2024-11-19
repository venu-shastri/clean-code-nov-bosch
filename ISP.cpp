// Online C++ compiler to run C++ program online
#include <iostream>
//Class interface (contract)
class IFileReader{
  public:
   virtual void read()=0;
};
class IFileWriter{
  public:
  virtual void write()=0;
};
class FileProcessor:public IFileReader,public IFileWriter {
  public:
        void write() override{}
        void read() override {}
};
void reader(IFileReader* processor){
    processor->read();
    //processor->write();
}
void writer(IFileWriter* processor){
    processor->write();
  // processor->read();
}
void readWrite(FileProcessor* processor){
    processor->read();
    processor->write();
}
int main() {
    FileProcessor processor;
    reader(&processor);
    writer(&processor);
    readWrite(&processor);
   
    return 0;
}
