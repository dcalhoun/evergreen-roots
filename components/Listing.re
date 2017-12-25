let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Listing");

let make = (~item: ListingData.item, _children) => {
  let sPrice = ReactDOMRe.Style.make(~fontFamily="sans-serif", ());
  {
    ...component,
    render: (_self) =>
      <article>
        <Heading priority=3> (str(item.title)) </Heading>
        <span style=sPrice> (str(item.price)) </span>
      </article>
  }
};
