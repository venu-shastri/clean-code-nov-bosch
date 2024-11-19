#include <stdio.h>

// Interfaces (contracts) using function pointers in structs
typedef struct IFileReader {
    void (*read)(void*);  // Function pointer for read method
} IFileReader;

typedef struct IFileWriter {
    void (*write)(void*); // Function pointer for write method
} IFileWriter;

// FileProcessor struct implementing both interfaces
typedef struct FileProcessor {
    IFileReader readerInterface;
    IFileWriter writerInterface;
} FileProcessor;

// Implementation of read method
void FileProcessor_read(void* self) {
    printf("FileProcessor: read()\n");
}

// Implementation of write method
void FileProcessor_write(void* self) {
    printf("FileProcessor: write()\n");
}

// Helper functions to simulate the behavior
void reader(IFileReader* processor) {
    processor->read(processor);  // Call the read function via interface
}

void writer(IFileWriter* processor) {
    processor->write(processor);  // Call the write function via interface
}

void readWrite(FileProcessor* processor) {
    processor->readerInterface.read(processor);  // Call read
    processor->writerInterface.write(processor);  // Call write
}

int main() {
    // Create a FileProcessor object and set up function pointers
    FileProcessor processor;
    processor.readerInterface.read = FileProcessor_read;
    processor.writerInterface.write = FileProcessor_write;

    // Pass FileProcessor as IFileReader and IFileWriter
    reader(&processor.readerInterface);
    writer(&processor.writerInterface);
    readWrite(&processor);

    return 0;
}
