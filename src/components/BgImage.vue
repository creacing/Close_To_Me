

<template>
  <div id="imgs" class="pjax">
    <ul>
      <li
        v-for="bgImageUrl in bgImageList"
        class="item lozaded"
        :data-background-image="bgImageUrl"
        data-loaded="true"
        :style="{
          'background-image': `url(${bgImageUrl})`
        }"
      ></li>
    </ul>
  </div>
</template>
<script setup>
const bgImageList = [
  'https://tva2.sinaimg.cn/large/6833939bly1gipewf5l51j20zk0m8b29.jpg',
  'https://tva2.sinaimg.cn/large/6833939bly1gipewkhf1zj20zk0m81kx.jpg',
  'https://tva2.sinaimg.cn/large/6833939bly1giclflwv2aj20zk0m84qp.jpg',
  'https://tva2.sinaimg.cn/large/6833939bly1giclfb3vzhj20zk0m8wny.jpg',
  'https://tva2.sinaimg.cn/large/6833939bly1giciszlczyj20zk0m816d.jpg',
  'https://tva2.sinaimg.cn/large/6833939bly1gicivghyooj20zk0m8dir.jpg',
]
</script>