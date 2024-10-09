class BrowserHistory {
    stack<string> backhistorystack;
    stack<string> fronthistorystack;

public:
    BrowserHistory(string homepage) { backhistorystack.push(homepage); 
    
    }

    void visit(string url) {
        backhistorystack.push(url);
        while (!fronthistorystack.empty()) {
            fronthistorystack.pop();
        }
    }

    string back(int steps) {
        for (int i = 0; i < steps; i++) {
            // make sure ki x steps hi jana
            if (backhistorystack.size() > 1) {
                string temp = backhistorystack.top();
                backhistorystack.pop();
                fronthistorystack.push(temp);
            }
        }
        
        return backhistorystack.top();
    }

    string forward(int steps) {
        for (int i = 0; i < steps; i++) {
            // make sure ki x steps hi jana
            if (!fronthistorystack.empty()) {
                string temp = fronthistorystack.top();
                fronthistorystack.pop();
                backhistorystack.push(temp);
            }
        }
        return backhistorystack.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */