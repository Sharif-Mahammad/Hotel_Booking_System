#include<iostream>
#include<vector>
using namespace std;


static int c=0;

class room{
private:
    //room no
    int room_no;
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
    int get_room_no(){
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
    int customer_id;
    string name;
    long phone;

public:
    //add customer
    customer(int customer_id, string name, long phone){
        this->customer_id = customer_id;
        this->name = name;
        this->phone = phone;
    }

    //display customer
    void customer_details(){
        cout<<"customer ID: "<<customer_id<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"phone: "<<phone<<endl;
    }

    //get customer id
    int get_customer_id(){
        return customer_id;
    }   
    //get customer name
    string get_name(){
        return name;
    }
    //get customer phone
    long get_phone(){
        return phone;
    }
};

class booking{
private:
    int booking_id;
    int customer_id;
    int room_no;
    int days;
    long total_amount;

public:
    booking(int booking_id, int customer_id, int room_no, int days, long total_amount){
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

    int get_booking_id(){
        return booking_id;
    }

    int get_customer_id(){
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
    void add_room(int room_no, string room_type, long price){
        rooms.push_back(room( room_type, price, true));
    }

    //add customers
    void add(int customer_id, string name, long phone){
        customers.push_back(customer(customer_id, name, phone));
    }

    //book rooms
    void book_rooms(int c_id, int r_no, int days, int b_id){
        for(auto &it: rooms){
            if(r_no == it.get_room_no() && it.get_availability()){
                it.set_availability(false);
                int total_amount = days * it.get_price();
                bookings.push_back(booking(b_id, c_id, r_no, days, total_amount));
                cout<<"room booked successfully."<<endl;
                return;
            }
        }
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
    void search_customers(int customer_id){
        for(auto &it: customers){
            if(it.get_customer_id() == customer_id){
                it.customer_details();
                return;
            }
        }
        cout<<"customer not found!"<<endl;
    }

    void generate_bill(int b_id, int c_id){
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
        cout<<"2.Checkout Rooms "<<endl;
        cout<<"3.Booking Room "<<endl;
        cout<<"4.Display Rooms Details "<<endl;
        cout<<"6.Display Customer Details "<<endl;
        cout<<"1.Add Rooms "<<endl;
        cout<<"1.Add Rooms "<<endl;
    }

}