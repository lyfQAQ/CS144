#include <stdexcept>

#include "byte_stream.hh"

using namespace std;

ByteStream::ByteStream( uint64_t capacity ) : capacity_( capacity ), buffer{} {}

void Writer::push( string data )
{
  // Your code here.
  size_t n = min(data.size(), capacity_ - buffer.size());
  
  for(size_t i = 0; i < n; i++) buffer.push_back(data[i]);
  num_bytes_pushed_ += n;

  // (void)data;
}

void Writer::close()
{
  // Your code here.
  closed_ = true;
}

void Writer::set_error()
{
  // Your code here.
  error_ = true;
}

bool Writer::is_closed() const
{
  // Your code here.
  return closed_;
}

uint64_t Writer::available_capacity() const
{
  // Your code here.
  return capacity_ - buffer.size();
}

uint64_t Writer::bytes_pushed() const
{
  // Your code here.
  return num_bytes_pushed_;
}

string_view Reader::peek() const
{
  // Your code here.
  return buffer.empty() ? string_view() : string_view(&buffer.front(), 1);
}

bool Reader::is_finished() const
{
  // Your code here.
  return closed_ && this->buffer.empty();
}

bool Reader::has_error() const
{
  // Your code here.
  return error_;
}

void Reader::pop( uint64_t len )
{
  // Your code here.
  if(len > buffer.size()) {
    return;
  }
  num_bytes_poped_ += len;
  while(len--) {
    buffer.pop_front();
  }
  // buffer.erase(buffer.begin(), buffer.begin() + len);
  
}

uint64_t Reader::bytes_buffered() const
{
  // Your code here.
  return buffer.size();
}

uint64_t Reader::bytes_popped() const
{
  // Your code here.
  return num_bytes_poped_;
}
