#include<bits/stdc++.h>
using namespace std;


static long c=0;
static long c1=138;
static long c2=1272; 
class room{
private:
    //room no
    long room_no;
    //room typr
    string room_type;
    //price
    long price;
    //is available
    bool available;
public:
    //add room
    room( string s, long p, bool b){
        room_no = ++c;
        room_type = s;
        price = p;
        available = b;
    }

    //display room details
    void room_details(){
        cout<<"room number: "<<room_no<<endl;
        cout<<"room type: "<<room_type<< endl;
        cout<<"price: "<<price<<endl;
        cout<<"availability: "<<available<<endl;
    }

    //update room details
    long get_room_no(){
        return room_no;
    }
    bool get_availability(){
        return available;
    }
    void set_availability(bool status){
        available = status;
    }
    long get_price(){
        return price;
    }
    string get_room_type(){
        return room_type;
    }
};

class customer{
private:
    long customer_id;
    string name, mail;

public:
    //add customer
    customer(long c_id, string name, string mail){
        this->customer_id = c_id;
        this->name = name;
        this->mail = mail;
    }

    //display customer
    void customer_details(){
        cout<<"customer ID: "<<customer_id<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"email: "<<mail<<endl;
    }

    //get customer id
    long get_customer_id(){
        return customer_id;
    }   
    //get customer name
    string get_name(){
        return name;
    }
    //get customer phone
    string get_mail(){
        return mail;
    }
};

class booking{
private:
    long booking_id;
    int customer_id;
    int room_no;
    int days;
    long total_amount;

public:
    booking(long booking_id, int customer_id, int room_no, int days, long total_amount){
        this->booking_id=booking_id;
        this->customer_id = customer_id;
        this->room_no = room_no;
        this->days = days;
        this->total_amount = total_amount*days;
    }


    //display booking
    void booking_details(){
        cout<<"Booking ID: "<<booking_id<<endl;
        cout<<"Customer ID: "<<customer_id<<endl;
        cout<<"Room Number: "<<room_no<<endl;
        cout<<"Booking days: "<<days<<endl;
        cout<<"Total Bill : "<<total_amount<<endl;
    }

    long get_booking_id(){
        return booking_id;
    }

    long get_customer_id(){
        return customer_id;
    }
};

class Hotel{
    private:
    vector<room>rooms;
    vector<customer>customers;
    vector<booking>bookings;

    public:
    //add rooms
    void add_room(string room_type, long price){
        rooms.push_back(room( room_type, price, true));
    }

    //add customers
    void add_customer(int c_id, string name, string mail){
        customers.push_back(customer(c_id, name, mail));
    }

    //book rooms
    void book_rooms(long c_id, int r_no, int days, long b_id){
        for(auto &it: rooms){
            if(r_no == it.get_room_no() && it.get_availability()){
                it.set_availability(false);
                int total_amount = days * it.get_price();
                bookings.push_back(booking(b_id, c_id, r_no, days, total_amount));
                cout<<"room booked successfully."<<endl;
                return;
            }
        }
        c2--;
        cout<<"sorry!, room is not availble"<<endl;
    }

    //checking out rooms
    void checkout_rooms(){
        cout<<"Available Rooms: "<<endl;
            for(auto &it: rooms){
                if(it.get_availability()==true){
                    cout<<"Room number: "<<it.get_room_no()<<"Room Type: "<<it.get_room_type()<<endl;
                    cout<<"Room price per day: "<<it.get_price()<<"Room avaiilability: "<<(it.get_availability() ? "YES" : "NO")<<endl;
                    cout<<endl;
                }
            }
    }

    //display rooms
    void display_rooms(){
        cout<<"Rooms: "<<endl;
        for(auto &it: rooms){
            it.room_details();
            cout<<endl;
        }
    }

    //display customers 
    void display_customers(){
        cout<<"Customers: "<<endl;
        for(auto &it: customers){
            it.customer_details();
            cout<<endl;
        }
    }

    //display bookings
    void display_bookings(){
        cout<<"Bookings: "<<endl;
        for(auto &it: bookings){
            it.booking_details();
            cout<<endl;
        }
    }

    //search for rooms

    //search for customers
    void search_customers(long customer_id){
        for(auto &it: customers){
            if(it.get_customer_id() == customer_id){
                it.customer_details();
                return;
            }
        }
        cout<<"customer not found!"<<endl;
    }

    void generate_bill(long b_id, long c_id){
        cout<<"Bill Details: "<<endl;
        for(auto &it: bookings){
            if(it.get_booking_id() == b_id && it.get_customer_id() == c_id){
                it.booking_details();
                return;
            }
        }
        cout<<"Booking Id not found!"<<endl;
    }

};


int main(){
    cout<<"-----Hotel Management System-----"<<endl;

    Hotel h;

    while(true){
        cout<<"1.Add Rooms "<<endl;
        cout<<"2.Checkout Rooms available"<<endl;
        cout<<"3.Book Rooms "<<endl;
        cout<<"4.Display Rooms Details "<<endl;
        cout<<"5.Display Customer Details "<<endl;
        cout<<"6.display bookings "<<endl;
        cout<<"7.Generate Bill "<<endl;
        cout<<"8.Exit "<<endl;

        int input;
        cin>>input;
        if(input == 1){
            long price;
            string type;

            cout<<"ter type: ";
            cin>>type;
            cout<<"enter room perice: ";
            cin>>price;

            h.add_room(type, price);
        }
        else if(input == 2){
            h.checkout_rooms();
        }
        else if(input == 3){
            long cid, rno, bid;
            int days;
            string name, mail;
            cid = ++c1;
            cout<<"enter customer name: ";
            cin>>name;
            cout<<"customer contact number";
            cin>>mail;

            //booking room
            cout<<"enter room number: ";
            cin>>rno;
            cout<<"enter Number of days: ";
            cin>>days;
            long chk = c2;
            bid = ++c2;
            h.book_rooms(cid, rno, days, c2);
            //customer will be added automatically
            if(c2 == bid);
            h.add_customer(cid, name, mail);
        }
        else if(input == 4){
            h.display_rooms();
        }else if(input == 5){
            h.display_customers();
        }
        else if(input == 6){
            h.display_bookings();
        }
        else if(input == 7){
            long bId, cId;
            cout<<"enter customer Id: ";
            cin>>cId;
            cout<<"enter booking Id: ";
            cin>>bId;
            h.generate_bill(bId, cId);
        }
        else if(input == 8){
            break;
        }
    }

}