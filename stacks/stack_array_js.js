class stack{
    constructor(){
        this.items = [];
    }
    
    push(element){
        this.items.push(element);
    }

    pop(){
        if(this.isEmpty()){
            console.log("cannot pop");
        }
        return this.items.pop();
    }

    peek(){
        if(this.isEmpty()){
            return "stack is empty";
        }
        return this.items[this.items.length-1];

    }

    isEmpty(){
        return this.items.length===0;
    }
    print(){
        console.log(this.items.toString());
    }
}

let st = new stack();

st.push(10);
st.push(30);
st.push(90);
console.log(st.peek()); 
st.pop();
console.log(st.peek());  

st.print(); 