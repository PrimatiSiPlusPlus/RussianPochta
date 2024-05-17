#pragma once
#include <string>
#include <vector>
#include <list>
class Parcel {
private:
	std::string senderName;
	std::string senderSurname;
	std::string recipientName;
	std::string recipientSurname;
	std::string trackNumber;
	int from;
	int where;
	int weight;
	time_t sentTime;
	time_t recieveTime;
	bool state;
public:
	std::string getSenderName();
	std::string getSenderSurname();
	std::string getRecipientName();
	std::string getRecipientSurname();
	std::string getTrackNumber();
	int getFrom();
	int getWhere();
	int getWeight();
	time_t getSentTime();
	time_t getReceiveTime();
	bool getState();


	void setSenderName(std::string SenderName);
	void setSenderSurname(std::string SenderSurname);
	void setRecipientName(std::string RecipientName);
	void setRecipientSurname(std::string RecipientSurname);
	void setTrackNumber(std::string TrackNumber);
	void setFrom(int From);
	void setWhere(int Where);
	void setWeight(int Weight);
	void setSentTime(time_t Time);
	void setReceiveTime(time_t Time);
	void setState(bool State);

	friend std::istream& operator>>(std::istream& in, Parcel& parcel);
	friend std::ostream& operator<<(std::ostream& out, const Parcel& parcel);
};
class PostOffice {
	//std::list<Parcels> listParcels;
	int index;
	std::string name;
	int coordinateX;
	int coordinateY;
public:
	int getIndex();
	std::string getNameOffice();
	int getCoordinateX();
	int getCoordinateY();
	void setIndex(int Index);
	void setCoordinateX(int X);
	void setCoordinateY(int Y);
	void setNameOffice(std::string Name);

	friend std::istream& operator>>(std::istream& in, PostOffice& office);
	friend std::ostream& operator<<(std::ostream& out, const PostOffice& office);
};

namespace PostOfficeControl {
	void createPostOffice(const int n); 
	void removePostOffice();
	void editPostOffice();
	void savePostOffice(std::vector<PostOffice> arr, const int& n);
	std::vector<PostOffice> readPostOffice();
	int getCountPostOffice();

	void sendParcel();
	void findParcel();
	int getCountParcel();
	void deliveryParcel();
	void checkStatusParcels();
	std::vector<Parcel> readParcel();
	void saveParcel(std::vector<Parcel> arr, const int& n);

	time_t timeLocation(PostOffice& sender, PostOffice& reciever);
	void rewindTime();
	void progressTime();
	void print();
	int inputInteger();
}