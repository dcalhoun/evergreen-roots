let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("ErrorMessage");

let make = (~message: string, _children) => {
  let sError = ReactDOMRe.Style.make(~fontFamily="sans-serif", ());
  {
    ...component,
    render: _self =>
      <div style=sError>
        <Heading priority=2> (str("Error")) </Heading>
        <P> (str(message)) </P>
      </div>,
  };
};
