let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("TextField");

let make = (~name, ~label=name, ~id=name, _children) => {
  let sLabel =
    ReactDOMRe.Style.make(~display="block", ~fontFamily="sans-serif", ());
  let sInput =
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
        <input style=sInput id name _type="text" />
      </div>
  }
};
