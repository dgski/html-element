# HTML Element

A simple html element rendering Class to generate HTML snippets. Very limited and provides a class which holds either:
- A list of sub-nodes
- The text value of the node

Simple use example:
``` c++

// Create Element
HTMLElement div = HTMLElement("div");

// Set Attributes
    div
        .setAttribute("class", "code")
        .setAttribute("style", "padding: 10px; color: white; background-color: black");

// Append A Child Div
div.appendChild(TextElement("This is a code block")); // TextElement is only special variant for Text Only Element

// Output the HTML value
output << div;
```

Output:
``` html
<div class="code" style="padding: 10px; color: white; background-color: black">
  This is a code block!
</div>
```
