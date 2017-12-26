let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("TextArea");

let make = (~name, ~id=name, ~label=name, ~placeholder="", _children) => {
  let sContainer = ReactDOMRe.Style.make(~marginBottom="1rem", ());
  let sLabel =
    ReactDOMRe.Style.make(
      ~display="block",
      ~fontFamily="sans-serif",
      ~marginBottom="0.25rem",
      ()
    );
  let sTextArea =
    ReactDOMRe.Style.make(
      ~border="1px solid #ccc",
      ~borderRadius="3px",
      ~boxShadow="none",
      ~boxSizing="border-box",
      ~fontFamily="sans-serif",
      ~fontSize="1rem",
      ~padding="0.5rem",
      ~width="100%",
      ()
    );
  {
    ...component,
    render: (_self) =>
      <div style=sContainer>
        <label style=sLabel htmlFor=name> (str(label)) </label>
        <textarea style=sTextArea id name placeholder />
      </div>
  }
};
