#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

// Document Element class for rendering various element. This will be an abstract class
class DocumentElement{
    public:
        virtual string render() = 0;
};

// TextElement class to render the texts
class TextElement : public DocumentElement{
    private:
        string text;

    public:
        TextElement(string text){
            this->text = text;
        }
        string render() override {
            return text;
        }
};

// ImageElement class to render images
class ImageElement : public DocumentElement{
    private:
        string path;
    
    public: 
        ImageElement(string path){
            this->path = path;
        }

        string render() override{
            return "[Image: " + path + " ]";
        }
};

class NewLineElement : public DocumentElement{
    public:
        string render() override {
            return "\n";
        }
};

class TabSpaceElement : public DocumentElement{
    public:
        string render() override {
            return "\t";
        }
};

// Document class that has a composition relation with DocumentElement
class Document{
    private:
        vector<DocumentElement*> documentElements;
    
    public:
        void addElement(DocumentElement* element){
            documentElements.push_back(element);
        }

        // here we create the render method whose job is to basically delegate the rendering work to the respective element class
        // Renders the document by concatenating the render output of all elements.
        string render(){
            string result;
            for(DocumentElement* el: documentElements){
                result += el->render();
            }
            return result;
        }
};

// For saving the file we will have a Persistence class
class Persistence{
    public:
        virtual void save(string data) = 0;
};

class saveToFile :  public Persistence{
    public:
        void save(string data) override {
            ofstream outFile("document.txt");
            if (outFile) {
                outFile << data;
                outFile.close();
                cout << "Document saved to document.txt" << endl;
            } else {
                cout << "Error: Unable to open file for writing." << endl;
            }
        }
};

// Placeholder DBStorage implementation
class DBStorage : public Persistence {
public:
    void save(string data) override {
        // Save to DB
    }
};

class DocumentEditor{
    private: 
        Document* document;
        Persistence* storage;
        string renderedDocument;
    
    public:
        DocumentEditor(Document* document, Persistence* storage){
            this->document = document;
            this->storage = storage;
        }

        void addText(string text){
            document->addElement(new TextElement(text));
        }

        void addImage(string path){
            document->addElement(new ImageElement(path));
        }

        // Adds a new line to the document.
        void addNewLine() {
            document->addElement(new NewLineElement());
        }

        // Adds a tab space to the document.
        void addTabSpace() {
            document->addElement(new TabSpaceElement());
        }

        string renderDocument(){
            if(renderedDocument.empty()){
                renderedDocument = document->render();
            }
            return renderedDocument;
        }

        void saveDocument(){
            storage->save(renderDocument());
        }
};

// Client
int main(){
    Document* document = new Document();
    Persistence* persistence = new saveToFile();
    DocumentEditor* editor = new DocumentEditor(document, persistence);

    // Simulate a client using the editor with common text formatting features.
    editor->addText("Hello, world!");
    editor->addNewLine();
    editor->addText("This is a real-world document editor example.");
    editor->addNewLine();
    editor->addTabSpace();
    editor->addText("Indented text after a tab space.");
    editor->addNewLine();
    editor->addImage("picture.jpg");

    // Render and display the final document
    cout << editor->renderDocument() << endl;

    editor->saveDocument();

    return 0;
}