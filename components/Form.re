let component = ReasonReact.statelessComponent("Form");

let make = (~onSubmit, children) => {
  let submit = event => {
    ReactEventRe.Synthetic.preventDefault(event);
    Js.log("submit");
    onSubmit();
  };
  {
    ...component,
    render: _self =>
      <form onSubmit=submit>
        (
          ReasonReact.createDomElement(
            "div",
            ~props={"className": ""},
            children,
          )
        )
      </form>,
  };
};
