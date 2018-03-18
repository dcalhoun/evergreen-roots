let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Listing");

let make = (~item: ListingData.item, _children) => {
  let sListing =
    ReactDOMRe.Style.make(
      ~border="1px solid #ccc",
      ~color="#555",
      ~display="block",
      ~fontFamily="sans-serif",
      ~marginBottom="1rem",
      ~padding="0.5rem",
      ~textDecoration="none",
      (),
    );
  let sPrice = ReactDOMRe.Style.make(~fontFamily="sans-serif", ());
  {
    ...component,
    render: _self =>
      <a
        href=item.url style=sListing target="_blank" rel="noopener noreferrer">
        <Heading scale=3 tagless=true> (str(item.title)) </Heading>
        <span style=sPrice> (str("$" ++ item.price)) </span>
      </a>,
  };
};
