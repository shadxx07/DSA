class BrowserHistory {
public:
class Node {
    public:
        string data;
        Node* back;
        Node* forward;

        Node(string url) {
            data = url;
            back = NULL;
            forward = NULL;
        }
    };

    Node* currentPage;
    BrowserHistory(string homepage) {
        currentPage = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode= new Node(url);
        currentPage->forward= newNode;
        newNode->back = currentPage;
        currentPage=newNode;
    }
    
    string back(int steps) {
        while(steps){
            if(currentPage->back){
                currentPage = currentPage->back;
            }
            else{
                break;
            }
            steps--;
        }
        return currentPage->data;
    }
    
    string forward(int steps) {
        while(steps){
            if(currentPage->forward){
                currentPage = currentPage->forward;
            }
            else{
                break;
            }
            steps--;
        }
        return currentPage->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */