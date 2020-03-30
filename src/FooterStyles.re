let reasonReactBlue = "#48a9dc";

// The {j|...|j} feature is just string interpolation, from
// bucklescript.github.io/docs/en/interop-cheatsheet#string-unicode-interpolation
// This allows us to conveniently write CSS, together with variables, by
// constructing a string
let style = {j|
  ul {
  display: inline-grid;
  grid-auto-flow: row;
  grid-gap: 24px;
  justify-items: center;
  margin: auto;
}

@media (min-width: 500px) {
  ul {
    grid-auto-flow: column;
  }
}

a {
  color: white;
  text-decoration: none;
  box-shadow: inset 0 -1px 0 hsla(0, 0%, 100%, 0.4);
}

a:hover {
  box-shadow: inset 0 -1.2em 0 hsla(0, 0%, 100%, 0.4);
}

li:last-child {
  grid-column: 1 / 2;
  grid-row: 1 / 2;
}

li:hover ~ li p {
  animation: wave-animation 0.3s infinite;
}

/* below is just for demo styling */

div {
  display: flex;
  height: 100vh;
  width: 100%;
  background-color: #002a38;
  line-height: 1.3;
  font-family: Menlo, monospace;
}

@keyframes wave-animation {
  0%,
  100% {
    transform: rotate(0deg);
  }
  25% {
    transform: rotate(20deg);
  }
  75% {
    transform: rotate(-15deg);
  }
}
|j};
