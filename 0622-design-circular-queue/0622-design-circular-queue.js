/**
 * @param {number} k
 */
var MyCircularQueue = function(k) {
    this.front =-1;
    this.rear=-1;
    this.arr = new Array(k).fill(-1)
    this.capacity =k;
    // front means jahan sai array start hoga
    // rare means jahan end hoga
    
};

/** 
 * @param {number} value
 * @return {boolean}
 */
MyCircularQueue.prototype.enQueue = function(value) {
    let f = this.front;
    let r = this.rear;
    let c = this.capacity
    if((r+1)%c==f){
        // means queue pura full ho gaya hai
        return false
    }
    if(f==-1 && r==-1){
        this.front=0;
    }
    this.rear = (this.rear+1)%c;
    this.arr[this.rear]= value;
    return true;
    
};

/**
 * @return {boolean}
 */
MyCircularQueue.prototype.deQueue = function() {

      let f = this.front;
    let r = this.rear;
    let c = this.capacity;
    // first check whether the queueu is empty or not
    if(f==-1 && r==-1){
        return false; 
        // means if both front and rear are minus 1 , then queue empty hai
    }
    if(f==r){
        // means there were only one elment after removing it make both front and rear as -1
        this.front =-1;
        this.rear =-1;
        return true
    }
    this.front = (this.front +1)%c;
    return true;
};

/**
 * @return {number}
 */
MyCircularQueue.prototype.Front = function() {
      let f = this.front;
    let r = this.rear;
    let c = this.capacity
    if(f==-1 && r==-1){
        return -1;
    }
    return this.arr[this.front]
    
};

/**
 * @return {number}
 */
MyCircularQueue.prototype.Rear = function() {
          let f = this.front;
    let r = this.rear;
    let c = this.capacity
    if(f==-1 && r==-1){
        return -1;
    }
    return this.arr[this.rear]
    
};

/**
 * @return {boolean}
 */
MyCircularQueue.prototype.isEmpty = function() {
          let f = this.front;
    let r = this.rear;
    let c = this.capacity
    if(f==-1 && r==-1){
        return true
    }
    return false    
};

/**
 * @return {boolean}
 */
MyCircularQueue.prototype.isFull = function() {
      let f = this.front;
    let r = this.rear;
    let c = this.capacity;
    if((r+1)%c==f){
        return true;
    }
    return false;
    
};

/** 
 * Your MyCircularQueue object will be instantiated and called as such:
 * var obj = new MyCircularQueue(k)
 * var param_1 = obj.enQueue(value)
 * var param_2 = obj.deQueue()
 * var param_3 = obj.Front()
 * var param_4 = obj.Rear()
 * var param_5 = obj.isEmpty()
 * var param_6 = obj.isFull()
 */