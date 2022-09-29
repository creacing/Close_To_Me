<template>
  <div class="copywrite">
    <div class="copywrite--content">
      © 2010 –
      <span>{{ currentYear }}</span>
      <span class="copywrite--icon">
        <i class="ic i-sakura rotate"></i>
      </span>
      <span class="copywrite--author">{{ author }}</span>
    </div>

    <div class="copywrite--power">
      基于
      <a
        href="https://hexo.io"
        rel="noopener external nofollow noreferrer"
        target="_blank"
        title="Hexo"
      >Hexo</a>
      &amp; Theme.
      <a
        href="https://github.com/amehime/hexo-theme-shoka"
        rel="noopener external nofollow noreferrer"
        target="_blank"
        class="font-pink"
        title="Shoka"
      >Shoka</a>
    </div>
  </div>
</template>
<script setup>
const author = 'cheshire cat';
const currentDate = new Date();
const currentYear = currentDate.getFullYear();
</script>
<style lang="scss" scoped>
.copywrite {
  width: 100%;
  text-align: center;
  margin-top: 2rem;
}
.copywrite--icon {
  color: hsl(350deg 100% 88%);
  display: inline-block;
  margin: 0 0.3125rem 0 0.125rem;
}
.copywrite--power {
  display: inline-block;
  margin-bottom: 0.625rem;
}
</style>