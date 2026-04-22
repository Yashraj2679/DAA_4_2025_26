// Queue using Array (DSA concept)
class Queue {
  constructor() {
    this.items = [];
  }

  enqueue(element) {
    this.items.push(element);
  }

  dequeue() {
    if (this.isEmpty()) return "Queue is empty";
    return this.items.shift();
  }

  isEmpty() {
    return this.items.length === 0;
  }

  getQueue() {
    return this.items;
  }
}

const queue = new Queue();

function addCustomer() {
  const input = document.getElementById("nameInput");
  const name = input.value.trim();

  if (name === "") {
    alert("Enter a name");
    return;
  }

  queue.enqueue(name);
  input.value = "";
  displayQueue();
}

function serveCustomer() {
  if (queue.isEmpty()) {
    alert("No customers in queue");
    return;
  }

  const served = queue.dequeue();
  alert(served + " is served!");
  displayQueue();
}

function displayQueue() {
  const list = document.getElementById("queueList");
  list.innerHTML = "";

  queue.getQueue().forEach((name, index) => {
    const li = document.createElement("li");
    li.textContent = name;

    if (index === 0) {
      li.classList.add("active"); // first person highlight
    }

    list.appendChild(li);
  });
}