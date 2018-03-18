let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("P");

let make = children => {
  let sParagraph = ReactDOMRe.Style.make(~fontFamily="sans-serif", ());
  {
    ...component,
    render: _self =>
      <p style=sParagraph> (ReasonReact.arrayToElement(children)) </p>,
  };
};
