let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Listings");

let make = (~items: ListingData.items, _children) => {
  let sEmpty =
    ReactDOMRe.Style.make(~fontFamily="sans-serif", ~textAlign="center", ());
  {
    ...component,
    render: _self =>
      Array.length(items) < 1 ?
        <div style=sEmpty> (str("No Listings")) </div> :
        ReasonReact.arrayToElement(
          Array.map(
            (item: ListingData.item) =>
              <Listing key=(string_of_int(item.listing_id)) item />,
            items,
          ),
        ),
  };
};
