[@react.component]
let make = () => 

  <div>
  <ul>
    <li><a href="https://twitter.com/_idkjs">{React.string("Twitter")}</a></li>
    <li><a href="mailto:aarmand.inbox@gmail.com">{React.string("Email")}</a></li>
    <li><a href="https://github.com/idkjs">{React.string("Github")}</a></li>
    <li>
      <p>{React.string({j|👋|j})}</p>
    </li>
  </ul>
</div>;