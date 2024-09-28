/**
 * @param {number} k
 */
var MyCircularDeque = function (k) {
    // this.front = -1;
    // this.rear = -1;
    this.array = [];
    this.k=k;

};

/** 
 * @param {number} value
 * @return {boolean}
 */
MyCircularDeque.prototype.insertFront = function (value) {
    
    if (this.array.length < this.k) {
        this.array.unshift(value);
        return true;
    }
    return false;

};

/** 
 * @param {number} value
 * @return {boolean}
 */
MyCircularDeque.prototype.insertLast = function (value) {
    if (this.array.length < this.k) {
        this.array.push(value);
        return true;
    }
    return false;

};

/**
 * @return {boolean}
 */
MyCircularDeque.prototype.deleteFront = function () {
    if (this.array.length > 0) {
        this.array.shift();
        return true;
    }
    return false;

};

/**
 * @return {boolean}
 */
MyCircularDeque.prototype.deleteLast = function () {
    if (this.array.length > 0) {
        this.array.pop();
        return true;
    }
    return false;
};

/**
 * @return {number}
 */
MyCircularDeque.prototype.getFront = function () {
    if (this.array.length < 1) {
        return -1;
    }
    return this.array[0]

};

/**
 * @return {number}
 */
MyCircularDeque.prototype.getRear = function () {
    if (this.array.length < 1) {
        return -1;
    }
    return this.array[this.array.length - 1];

};

/**
 * @return {boolean}
 */
MyCircularDeque.prototype.isEmpty = function () {
    if (this.array.length < 1) {
        return true
    }
    return false;

};

/**
 * @return {boolean}
 */
MyCircularDeque.prototype.isFull = function () {

    if (this.array.length >= this.k) {
        return true
    }
    return false;

};

/** 
 * Your MyCircularDeque object will be instantiated and called as such:
 * var obj = new MyCircularDeque(this.k)
 * var param_1 = obj.insertFront(value)
 * var param_2 = obj.insertLast(value)
 * var param_3 = obj.deleteFront()
 * var param_4 = obj.deleteLast()
 * var param_5 = obj.getFront()
 * var param_6 = obj.getRear()
 * var param_7 = obj.isEmpty()
 * var param_8 = obj.isFull()
 */