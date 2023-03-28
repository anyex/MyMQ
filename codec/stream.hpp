// // #include <iostream>
// // #include <streambuf>
// // #include <vector>
// // #include <sys/socket.h>
// // #include <netinet/in.h>
// // #include <arpa/inet.h>

// // class SocketStream {
// // public:
// //     SocketStream(int sockfd) : sockfd_(sockfd), inbuf_(sockfd), outbuf_(sockfd) {}

// //     // 从输入流中读取一个数据包
// //     std::vector<char> readPacket() {
// //         std::vector<char> packet;
// //         // 读取报头
// //         int packetLen;
// //         if (inbuf_.sgetn(reinterpret_cast<char*>(&packetLen), sizeof(packetLen)) != sizeof(packetLen)) {
// //             return packet;
// //         }
// //         packetLen = ntohl(packetLen);
// //         // 读取数据部分
// //         packet.resize(packetLen);
// //         if (inbuf_.sgetn(packet.data(), packetLen) != packetLen) {
// //             packet.clear();
// //         }
// //         return packet;
// //     }

// //     // 向输出流中写入一个数据包
// //     bool writePacket(const std::vector<char>& packet) {
// //         // 写入报头
// //         int packetLen = htonl(packet.size());
// //         if (outbuf_.sputn(reinterpret_cast<const char*>(&packetLen), sizeof(packetLen)) != sizeof(packetLen))
// //     };

// // }


// #include <iostream>
// #include <cstring>
// #include <cstdlib>
// #include <arpa/inet.h>
// #include <unistd.h>
// #include <sys/socket.h>
// #include <streambuf>
// #include <stdexcept>

// class SocketStreambuf : public std::streambuf {
// public:
//     explicit SocketStreambuf(int sockfd) : sockfd_(sockfd), buffer_(nullptr), buffer_size_(0), buffer_pos_(0) {}

//     ~SocketStreambuf() {
//         if (buffer_) {
//             delete[] buffer_;
//         }
//     }

//     // 重载streambuf的xsputn方法，用于发送数据包
//     std::streamsize xsputn(const char* s, std::streamsize n) override {
//         // 计算数据包大小
//         size_t packet_size = n + sizeof(size_t);

//         // 将数据包大小转换为网络字节序
//         packet_size = htonl(packet_size);

//         // 发送数据包大小
//         ssize_t sent = send(sockfd_, &packet_size, sizeof(packet_size), 0);
//         if (sent != sizeof(packet_size)) {
//             throw std::runtime_error("send packet size failed");
//         }

//         // 发送数据包内容
//         sent = send(sockfd_, s, n, 0);
//         if (sent != n) {
//             throw std::runtime_error("send packet data failed");
//         }

//         return n;
//     }

//     // 重载streambuf的xsgetn方法，用于接收数据包
//     std::streamsize xsgetn(char* s, std::streamsize n) override {
//         std::streamsize total = 0;

//         while (total < n) {
//             if (buffer_pos_ == buffer_size_) {
//                 // 接收数据包大小
//                 size_t packet_size;
//                 ssize_t received = recv(sockfd_, &packet_size, sizeof(packet_size), 0);
//                 if (received != sizeof(packet_size)) {
//                     throw std::runtime_error("receive packet size failed");
//                 }

//                 // 将数据包大小转换为主机字节序
//                 packet_size = ntohl(packet_size);

//                 // 判断数据包大小是否合法
//                 if (packet_size > buffer_size_) {
//                     if (buffer_) {
//                         delete[] buffer_;
//                     }
//                     buffer_size_ = packet_size;
//                     buffer_ = new char[buffer_size_];
//                 }

//                 // 接收数据包内容
//                 ssize_t received_data = recv(sockfd_, buffer_, packet_size - sizeof(size_t), 0);
//                 if (received_data != packet_size - sizeof(size_t)) {
//                     throw std::runtime_error("receive packet data failed");
//                 }

//                 buffer_pos_ = 0;
//             }

//             // 将数据包内容复制到输出缓冲区中
//             std::streamsize count = std::min(n - total, static_cast<std::streamsize>(buffer_size_ - buffer_pos_));
//             std::memcpy(s + total, buffer_ + buffer_pos_, count);
//             buffer_pos_ += count;
//             total += count;
//         }

//         return total;
//     }

// private:
//     int sockfd_;
//     char* buffer_;
//     size_t buffer_size_;
//     size_t buffer_pos_;
// };

// class SocketStream : public std::iostream {
// public:
//     explicit SocketStream(int sockfd) : std::iostream(&streambuf_), streambuf_(sockfd) {}

// private:
//     SocketStreambuf streambuf_;
// };

#include <iostream>
#include <bitset>
#include <sstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>


class StreamBuf:public std::streambuf{
public:
   StreamBuf(int socketfd,ssize_t buf_size = 1024);
   virtual ~StreamBuf();

   int underflow();
   int overflow(int c=traits_type::eof());
   int sync();

   std::streamsize xsputn(const char* s,std::streamsize n);
   std::streamsize xsgetn(char* s, std::streamsize n);
protected:
   virtual ssize_t grecv(void *buf,ssize_t len,int flags) ;
   virtual ssize_t psend(const void *buf,ssize_t len,int flags);
   
   ssize_t m_buf_size;
   int m_socket_fd;
};

class SocketStream :public std::iostream{
   public:
      SocketStream(int sockfd,ssize_t size = 1024);
      
      virtual ~SocketStream();
   protected:
      ssize_t m_buf_size;
      int m_socket_fd;
};
