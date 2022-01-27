#include<bits/stdc++.h>
#include<string.h>
using namespace std;

string encode(string raw, int frame_size) {
  string result;
  int frame_count = (raw.length() / (frame_size - 1));
  int last_frame = raw.length() % (frame_size - 1);
  for (int i = 0; i < raw.length(); i++) {
    if (i % (frame_size - 1) == 0) {
      if (frame_count) {
        frame_count--;
        result += to_string(frame_size);
      } else {
        result += to_string(last_frame + 1);
      }
    }
    result += raw[i];
  }
  return result;
}

string decode(string encoded){
    int counter =0;
    string result = "";
    while(counter < encoded.length()){ 
        int frame_size = encoded[counter] - '0';
        result += encoded.substr(counter+1,frame_size-1);
        counter += frame_size;
    }
    return result;
}

int main(){
    
   cout<<"Byte Counting Frame Algoithm"<<endl;
   cout<<"Enter the string to be sent: ";
   string raw;
   cin>>raw;
   cout<<"Enter the frame size:";
   int size;
   cin>>size;
   string encoded = encode(raw,size);
   cout<<endl<<"Encoded String is - "<<encoded;
   cout<<endl<<"\n\nOn Receiver Side";
   string decoded = decode(encoded);
   cout<<endl<<"Decoded String is - "<<decoded<<endl;;
   
   if(raw == decoded)
    cout<<"\nTransmission done successfully."<<endl;
   else
    cout<<"\nTransmission unsuccessful"<<endl;
}