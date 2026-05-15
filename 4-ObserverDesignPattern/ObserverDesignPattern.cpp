#include <iostream>
#include <vector>

using namespace std;

// Pure abstract class for the Subscriber (Observer)
class ISubscriber {
    public: 
        virtual void update () = 0;
        virtual ~ISubscriber () {}; // virtual destructure for interface
};

// Pure abstract class for the Observable
class IChannel {
    public:
        virtual void subscribe (ISubscriber* s) = 0;
        virtual void unsubscribe (ISubscriber* s) = 0;
        virtual void notify() = 0;
        virtual ~IChannel() {};
};

// Concrete class for the IChannel
class Channel : public IChannel {
    private: 
        string name;
        vector<ISubscriber*> subscribers;
        string latestVideo;
    public:
        Channel(const string& name){
            this->name = name;
        }
        void subscribe (ISubscriber* subscriber) override {
            // Add a subscriber and make sure to avoid duplicate
            if (find(subscribers.begin(), subscribers.end(), subscriber) == subscribers.end()){
                subscribers.push_back(subscriber);
            }
        }

        void unsubscribe (ISubscriber* subscriber) override {
            // Remove a subscriber
            auto it = find(subscribers.begin(), subscribers.end(), subscriber);
            if (it != subscribers.end()){
                subscribers.erase(it);
            }
        }

        void notify() override {
            for (ISubscriber* subs : subscribers) {
                subs->update();
                // std::cout << element << " ";
            }
        }

        void uploadVideo(const string& title){
            latestVideo = title;
            cout << name << " uploaded a video " << title << "!!!"<< endl;
            notify();
        }

        string getVideoData(){
            return "\nThis is our new video: " + latestVideo + "\n";
        }
};

// Concrete Class for the subscriber (Represents a subscriber)
class Subscriber : public ISubscriber {
    private:
        string name;
        Channel* channel;
    public:
        Subscriber(const string& name, Channel* channel){
            this->name = name;
            this->channel = channel;
        }
        void update () override {
            cout << "Hey " << name << this->channel->getVideoData();
        }
};

int main(){
    // Create a channel and subscribers
    Channel* channel = new Channel("Saniels Channel");

    Subscriber* sub1 = new Subscriber("Osh", channel);
    Subscriber* sub2 = new Subscriber("Pranav", channel);

    // Osh and Pranav subscribe to channel
    channel->subscribe(sub1);
    channel->subscribe(sub2);

    // Channel uploads a video
    channel->uploadVideo("LLD Series");

    // Pranav unsubscribes
    channel->unsubscribe(sub2);

    // Uploading another video
    channel->uploadVideo("HLD Series");


    return 0;
}