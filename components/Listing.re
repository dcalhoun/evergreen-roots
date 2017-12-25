let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Listing");

let make = (~item: ListingData.item, _children) => {
  let sListing =
    ReactDOMRe.Style.make(
      ~border="1px solid #ccc",
      ~fontFamily="sans-serif",
      ~marginBottom="1rem",
      ~padding="0.5rem",
      ()
    );
  let sPrice = ReactDOMRe.Style.make(~fontFamily="sans-serif", ());
  {
    ...component,
    render: (_self) =>
      <article style=sListing>
        <Heading priority=3> (str(item.title)) </Heading>
        <span style=sPrice> (str("$" ++ item.price)) </span>
      </article>
  }
};
