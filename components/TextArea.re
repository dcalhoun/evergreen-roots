let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("TextArea");

let make = (~name, ~label=name, ~id=name, _children) => {
  let sLabel =
    ReactDOMRe.Style.make(~display="block", ~fontFamily="sans-serif", ());
  let sTextArea =
    ReactDOMRe.Style.make(
      ~border="1px solid #ccc",
      ~borderRadius="3px",
      ~boxShadow="none",
      ~fontFamily="sans-serif",
      ~width="100%",
      ()
    );
  {
    ...component,
    render: (_self) =>
      <div>
        <label style=sLabel htmlFor=name> (str(label)) </label>
        <textarea style=sTextArea id name />
      </div>
  }
};
