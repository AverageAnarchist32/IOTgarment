const express = require('express');
const bodyParser = require('body-parser');
const app = express();
const port = 3000; // You can specify the port you want to use

app.use(bodyParser.json());

app.use(express.static('public'));

// To store the current LED color state
let currentColor = 'off';

app.get('/setcolor', (req, res) => {
  const color = req.query.color;
  // Validate and set the current LED color state
  if (color === 'red' || color === 'blue' || color === 'off') {
    currentColor = color;
    res.status(200).send('Color set to ' + color);
  } else {
    res.status(400).send('Invalid color selection');
  }
});

app.get('/getcolor', (req, res) => {
  res.status(200).json({ color: currentColor });
});

app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});
